#ifndef BOOST_QVM_GEN_VEC_ASSIGN2_HPP_INCLUDED
#define BOOST_QVM_GEN_VEC_ASSIGN2_HPP_INCLUDED

/// Copyright (c) 2008-2021 Emil Dotchevski and Reverge Studios, Inc.

/// Distributed under the Boost Software License, Version 1.0. (See accompanying
/// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/// This file was generated by a program. Do not edit manually.

#include <boost/qvm/enable_if.hpp>
#include <boost/qvm/inline.hpp>
#include <boost/qvm/vec_traits.hpp>

namespace boost { namespace qvm {

template <class A,class B>
BOOST_QVM_CONSTEXPR BOOST_QVM_INLINE_OPERATIONS
typename enable_if_c<
    vec_traits<A>::dim==2 && vec_traits<B>::dim==2,
    A &>::type
assign( A & a, B const & b )
    {
    vec_traits<A>::template write_element<0>(a)=vec_traits<B>::template read_element<0>(b);
    vec_traits<A>::template write_element<1>(a)=vec_traits<B>::template read_element<1>(b);
    return a;
    }

namespace
sfinae
    {
    using ::boost::qvm::assign;
    }

namespace
qvm_detail
    {
    template <int D>
    struct assign_vv_defined;

    template <>
    struct
    assign_vv_defined<2>
        {
        static bool const value=true;
        };
    }

} }

#endif
