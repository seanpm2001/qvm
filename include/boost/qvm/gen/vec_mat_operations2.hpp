#ifndef BOOST_QVM_GEN_VEC_MAT_OPERATIONS2_HPP_INCLUDED
#define BOOST_QVM_GEN_VEC_MAT_OPERATIONS2_HPP_INCLUDED

/// Copyright (c) 2008-2021 Emil Dotchevski and Reverge Studios, Inc.

/// Distributed under the Boost Software License, Version 1.0. (See accompanying
/// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/// This file was generated by a program. Do not edit manually.

#include <boost/qvm/deduce_vec.hpp>
#include <boost/qvm/enable_if.hpp>
#include <boost/qvm/inline.hpp>
#include <boost/qvm/mat_traits.hpp>
#include <boost/qvm/vec_traits.hpp>

namespace boost { namespace qvm {

template <class A,class B>
BOOST_QVM_CONSTEXPR BOOST_QVM_INLINE_OPERATIONS
typename lazy_enable_if_c<
    mat_traits<A>::rows==2 && mat_traits<A>::cols==2 &&
    vec_traits<B>::dim==2,
    deduce_vec2<A,B,2> >::type
operator*( A const & a, B const & b )
    {
    typedef typename mat_traits<A>::scalar_type Ta;
    typedef typename vec_traits<B>::scalar_type Tb;
    Ta const a00 = mat_traits<A>::template read_element<0,0>(a);
    Ta const a01 = mat_traits<A>::template read_element<0,1>(a);
    Ta const a10 = mat_traits<A>::template read_element<1,0>(a);
    Ta const a11 = mat_traits<A>::template read_element<1,1>(a);
    Tb const b0 = vec_traits<B>::template read_element<0>(b);
    Tb const b1 = vec_traits<B>::template read_element<1>(b);
    typedef typename deduce_vec2<A,B,2>::type R;
    BOOST_QVM_STATIC_ASSERT(vec_traits<R>::dim==2);
    R r;
    vec_traits<R>::template write_element<0>(r)=a00*b0+a01*b1;
    vec_traits<R>::template write_element<1>(r)=a10*b0+a11*b1;
    return r;
    }

namespace
sfinae
    {
    using ::boost::qvm::operator*;
    }

namespace
qvm_detail
    {
    template <int R,int C>
    struct mul_mv_defined;

    template <>
    struct
    mul_mv_defined<2,2>
        {
        static bool const value=true;
        };
    }

template <class A,class B>
BOOST_QVM_CONSTEXPR BOOST_QVM_INLINE_OPERATIONS
typename lazy_enable_if_c<
    mat_traits<B>::rows==2 && mat_traits<B>::cols==2 &&
    vec_traits<A>::dim==2,
    deduce_vec2<A,B,2> >::type
operator*( A const & a, B const & b )
    {
    typedef typename vec_traits<A>::scalar_type Ta;
    typedef typename mat_traits<B>::scalar_type Tb;
    Ta const a0 = vec_traits<A>::template read_element<0>(a);
    Ta const a1 = vec_traits<A>::template read_element<1>(a);
    Tb const b00 = mat_traits<B>::template read_element<0,0>(b);
    Tb const b01 = mat_traits<B>::template read_element<0,1>(b);
    Tb const b10 = mat_traits<B>::template read_element<1,0>(b);
    Tb const b11 = mat_traits<B>::template read_element<1,1>(b);
    typedef typename deduce_vec2<A,B,2>::type R;
    BOOST_QVM_STATIC_ASSERT(vec_traits<R>::dim==2);
    R r;
    vec_traits<R>::template write_element<0>(r)=a0*b00+a1*b10;
    vec_traits<R>::template write_element<1>(r)=a0*b01+a1*b11;
    return r;
    }

namespace
sfinae
    {
    using ::boost::qvm::operator*;
    }

namespace
qvm_detail
    {
    template <int R,int C>
    struct mul_vm_defined;

    template <>
    struct
    mul_vm_defined<2,2>
        {
        static bool const value=true;
        };
    }

} }

#endif
