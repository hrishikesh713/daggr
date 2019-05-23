#ifndef DAGGR_NODES_H
#define DAGGR_NODES_H

/*----- System Includes -----*/

#include <dart.h>
#include <chrono>
#include <optional>
#include <functional>
#include <type_traits>

/*----- Type Declarations -----*/

namespace daggr {

  namespace node {

    template <class>
    class comp;
    template <class, class>
    class seq;
    template <class...>
    class all;

    using clock = std::chrono::steady_clock;

  }

  template <class T>
  struct is_node : std::false_type {};
  template <class T>
  struct is_node<node::comp<T>> : std::true_type {};
  template <class P, class C>
  struct is_node<node::seq<P, C>> : std::true_type {};
  template <class... Ts>
  struct is_node<node::all<Ts...>> : std::true_type {};
  template <class T>
  constexpr auto is_node_v = is_node<T>::value;

}

/*----- Local Includes -----*/

#include "lifecycle_traits.h"
#include "function_traits.h"
#include "helper.h"
#include "comp.h"
#include "seq.h"
#include "all.h"

/*----- Globals -----*/

namespace daggr {

  namespace detail {
    struct noop_comp {
      dart::packet operator ()(dart::packet const& pkt) {
        return pkt;
      }
    };
  }

  // Used to bootstrap the chaining API.
  inline daggr::node::comp<detail::noop_comp> const noop;

}

#endif
