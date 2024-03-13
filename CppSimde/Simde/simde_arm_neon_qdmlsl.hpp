/* SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Copyright:
 *   2023      Yi-Yen Chung <eric681@andestech.com> (Copyright owned by Andes Technology)
 */

#if !defined(SIMDE_ARM_NEON_QDMLSL_H)
#define SIMDE_ARM_NEON_QDMLSL_H

#include <CppSimde/simde_arm_neon_sub.hpp>
#include <CppSimde/simde_arm_neon_mul.hpp>
#include <CppSimde/simde_arm_neon_mul_n.hpp>
#include <CppSimde/simde_arm_neon_movl.hpp>
#include <CppSimde/simde_arm_neon_types.hpp>

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
int32_t
simde_vqdmlslh_s16(int32_t a, int16_t b, int16_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vqdmlslh_s16(a, b, c);
  #else
    return a - HEDLEY_STATIC_CAST(int32_t, b) * HEDLEY_STATIC_CAST(int32_t, c) * 2;
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vqdmlslh_s16
  #define vqdmlslh_s16(a, b, c) simde_vqdmlslh_s16((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
int64_t
simde_vqdmlsls_s32(int64_t a, int32_t b, int32_t c) {
  #if defined(SIMDE_ARM_NEON_A64V8_NATIVE)
    return vqdmlsls_s32(a, b, c);
  #else
    return a - HEDLEY_STATIC_CAST(int64_t, b) * HEDLEY_STATIC_CAST(int64_t, c) * 2;
  #endif
}
#if defined(SIMDE_ARM_NEON_A64V8_ENABLE_NATIVE_ALIASES)
  #undef vqdmlsls_s32
  #define vqdmlsls_s32(a, b, c) simde_vqdmlsls_s32((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int32x4_t
simde_vqdmlsl_s16(simde_int32x4_t a, simde_int16x4_t b, simde_int16x4_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vqdmlsl_s16(a, b, c);
  #else
    return simde_vsubq_s32(a, simde_vmulq_n_s32(simde_vmulq_s32(simde_vmovl_s16(b), simde_vmovl_s16(c)), 2));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqdmlsl_s16
  #define vqdmlsl_s16(a, b, c) simde_vqdmlsl_s16((a), (b), (c))
#endif

SIMDE_FUNCTION_ATTRIBUTES
simde_int64x2_t
simde_vqdmlsl_s32(simde_int64x2_t a, simde_int32x2_t b, simde_int32x2_t c) {
  #if defined(SIMDE_ARM_NEON_A32V7_NATIVE)
    return vqdmlsl_s32(a, b, c);
  #else
    simde_int64x2_private r_ = simde_int64x2_to_private(
          simde_x_vmulq_s64(
          simde_vmovl_s32(b),
          simde_vmovl_s32(c)));

    SIMDE_VECTORIZE
    for (size_t i = 0 ; i < (sizeof(r_.values) / sizeof(r_.values[0])) ; i++) {
      r_.values[i] = r_.values[i] * HEDLEY_STATIC_CAST(int64_t, 2);
    }

    return simde_vsubq_s64(a, simde_int64x2_from_private(r_));
  #endif
}
#if defined(SIMDE_ARM_NEON_A32V7_ENABLE_NATIVE_ALIASES)
  #undef vqdmlsl_s32
  #define vqdmlsl_s32(a, b, c) simde_vqdmlsl_s32((a), (b), (c))
#endif


SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_ARM_NEON_QDMLSL_H) */
