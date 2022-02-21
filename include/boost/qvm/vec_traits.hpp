// Copyright 2008-2022 Emil Dotchevski and Reverge Studios, Inc.

// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_QVM_VEC_TRAITS_HPP_INCLUDED
#define BOOST_QVM_VEC_TRAITS_HPP_INCLUDED

#include <boost/qvm/is_scalar.hpp>
#include <boost/qvm/enable_if.hpp>
#include <boost/qvm/inline.hpp>

namespace boost { namespace qvm {

template <class V>
struct
vec_traits
    {
    static int const dim=0;
    typedef void scalar_type;
    };

template <class T>
struct
is_vec
    {
    static bool const value = is_scalar<typename vec_traits<T>::scalar_type>::value && vec_traits<T>::dim>0;
    };

namespace
qvm_detail
    {
    struct vtr_dispatch_type1 { int a[1]; };
    struct vtr_dispatch_type2 { int a[2]; };

    template <class T, class U>
    vtr_dispatch_type1 vtr_dispatch(T (*)(U));
    vtr_dispatch_type2 vtr_dispatch(...);
    }

template <class,class=void>
struct
vec_write_element_ref
    {
    static bool const value = false;
    };

template <class T>
struct
vec_write_element_ref<T,
    typename enable_if_c<
        sizeof(qvm_detail::vtr_dispatch(&vec_traits<T>::template write_element<0>)) == sizeof(qvm_detail::vtr_dispatch_type1)>::type>
    {
    static bool const value = true;
    };

template <int I, class V>
BOOST_QVM_CONSTEXPR BOOST_QVM_INLINE_CRITICAL
typename enable_if_c<
    vec_write_element_ref<V>::value,
    void>::type
write_vec_element( V & v, typename vec_traits<V>::scalar_type s )
    {
    vec_traits<V>::template write_element<I>(v) = s;
    }

template <int I, class V>
BOOST_QVM_CONSTEXPR BOOST_QVM_INLINE_CRITICAL
typename enable_if_c<
    !vec_write_element_ref<V>::value,
    void>::type
write_vec_element( V & v, typename vec_traits<V>::scalar_type s )
    {
    vec_traits<V>::template write_element<I>(v, s);
    }

template <class V>
BOOST_QVM_CONSTEXPR BOOST_QVM_INLINE_CRITICAL
typename enable_if_c<
    vec_write_element_ref<V>::value,
    void>::type
write_vec_element_idx( int i, V & v, typename vec_traits<V>::scalar_type s )
    {
    vec_traits<V>::write_element_idx(i, v) = s;
    }

template <class V>
BOOST_QVM_CONSTEXPR BOOST_QVM_INLINE_CRITICAL
typename enable_if_c<
    !vec_write_element_ref<V>::value,
    void>::type
write_vec_element_idx( int i, V & v, typename vec_traits<V>::scalar_type s )
    {
    vec_traits<V>::write_element_idx(i, v, s);
    }

} }

#endif
