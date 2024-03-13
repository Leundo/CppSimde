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
 *   2020      Evan Nemerson <evan@nemerson.com>
 */

#if !defined(SIMDE_X86_AVX512_H)
#define SIMDE_X86_AVX512_H

#include <CppSimde/simde_x86_avx512_types.hpp>

#include <CppSimde/simde_x86_avx512_2intersect.hpp>
#include <CppSimde/simde_x86_avx512_4dpwssd.hpp>
#include <CppSimde/simde_x86_avx512_4dpwssds.hpp>
#include <CppSimde/simde_x86_avx512_abs.hpp>
#include <CppSimde/simde_x86_avx512_add.hpp>
#include <CppSimde/simde_x86_avx512_adds.hpp>
#include <CppSimde/simde_x86_avx512_and.hpp>
#include <CppSimde/simde_x86_avx512_andnot.hpp>
#include <CppSimde/simde_x86_avx512_avg.hpp>
#include <CppSimde/simde_x86_avx512_bitshuffle.hpp>
#include <CppSimde/simde_x86_avx512_blend.hpp>
#include <CppSimde/simde_x86_avx512_broadcast.hpp>
#include <CppSimde/simde_x86_avx512_cast.hpp>
#include <CppSimde/simde_x86_avx512_cmp.hpp>
#include <CppSimde/simde_x86_avx512_cmpeq.hpp>
#include <CppSimde/simde_x86_avx512_cmpge.hpp>
#include <CppSimde/simde_x86_avx512_cmpgt.hpp>
#include <CppSimde/simde_x86_avx512_cmple.hpp>
#include <CppSimde/simde_x86_avx512_cmplt.hpp>
#include <CppSimde/simde_x86_avx512_cmpneq.hpp>
#include <CppSimde/simde_x86_avx512_compress.hpp>
#include <CppSimde/simde_x86_avx512_conflict.hpp>
#include <CppSimde/simde_x86_avx512_copysign.hpp>
#include <CppSimde/simde_x86_avx512_cvt.hpp>
#include <CppSimde/simde_x86_avx512_cvtt.hpp>
#include <CppSimde/simde_x86_avx512_cvts.hpp>
#include <CppSimde/simde_x86_avx512_cvtus.hpp>
#include <CppSimde/simde_x86_avx512_dbsad.hpp>
#include <CppSimde/simde_x86_avx512_div.hpp>
#include <CppSimde/simde_x86_avx512_dpbf16.hpp>
#include <CppSimde/simde_x86_avx512_dpbusd.hpp>
#include <CppSimde/simde_x86_avx512_dpbusds.hpp>
#include <CppSimde/simde_x86_avx512_dpwssd.hpp>
#include <CppSimde/simde_x86_avx512_dpwssds.hpp>
#include <CppSimde/simde_x86_avx512_expand.hpp>
#include <CppSimde/simde_x86_avx512_extract.hpp>
#include <CppSimde/simde_x86_avx512_fixupimm.hpp>
#include <CppSimde/simde_x86_avx512_fixupimm_round.hpp>
#include <CppSimde/simde_x86_avx512_flushsubnormal.hpp>
#include <CppSimde/simde_x86_avx512_fmadd.hpp>
#include <CppSimde/simde_x86_avx512_fmsub.hpp>
#include <CppSimde/simde_x86_avx512_fnmadd.hpp>
#include <CppSimde/simde_x86_avx512_fnmsub.hpp>
#include <CppSimde/simde_x86_avx512_fpclass.hpp>
#include <CppSimde/simde_x86_avx512_gather.hpp>
#include <CppSimde/simde_x86_avx512_insert.hpp>
#include <CppSimde/simde_x86_avx512_kand.hpp>
#include <CppSimde/simde_x86_avx512_kshift.hpp>
#include <CppSimde/simde_x86_avx512_knot.hpp>
#include <CppSimde/simde_x86_avx512_kxor.hpp>
#include <CppSimde/simde_x86_avx512_load.hpp>
#include <CppSimde/simde_x86_avx512_loadu.hpp>
#include <CppSimde/simde_x86_avx512_lzcnt.hpp>
#include <CppSimde/simde_x86_avx512_madd.hpp>
#include <CppSimde/simde_x86_avx512_maddubs.hpp>
#include <CppSimde/simde_x86_avx512_max.hpp>
#include <CppSimde/simde_x86_avx512_min.hpp>
#include <CppSimde/simde_x86_avx512_mov.hpp>
#include <CppSimde/simde_x86_avx512_mov_mask.hpp>
#include <CppSimde/simde_x86_avx512_movm.hpp>
#include <CppSimde/simde_x86_avx512_mul.hpp>
#include <CppSimde/simde_x86_avx512_mulhi.hpp>
#include <CppSimde/simde_x86_avx512_mulhrs.hpp>
#include <CppSimde/simde_x86_avx512_mullo.hpp>
#include <CppSimde/simde_x86_avx512_multishift.hpp>
#include <CppSimde/simde_x86_avx512_negate.hpp>
#include <CppSimde/simde_x86_avx512_or.hpp>
#include <CppSimde/simde_x86_avx512_packs.hpp>
#include <CppSimde/simde_x86_avx512_packus.hpp>
#include <CppSimde/simde_x86_avx512_permutex.hpp>
#include <CppSimde/simde_x86_avx512_permutexvar.hpp>
#include <CppSimde/simde_x86_avx512_permutex2var.hpp>
#include <CppSimde/simde_x86_avx512_popcnt.hpp>
#include <CppSimde/simde_x86_avx512_range.hpp>
#include <CppSimde/simde_x86_avx512_range_round.hpp>
#include <CppSimde/simde_x86_avx512_rcp.hpp>
#include <CppSimde/simde_x86_avx512_reduce.hpp>
#include <CppSimde/simde_x86_avx512_rol.hpp>
#include <CppSimde/simde_x86_avx512_rolv.hpp>
#include <CppSimde/simde_x86_avx512_ror.hpp>
#include <CppSimde/simde_x86_avx512_rorv.hpp>
#include <CppSimde/simde_x86_avx512_round.hpp>
#include <CppSimde/simde_x86_avx512_roundscale.hpp>
#include <CppSimde/simde_x86_avx512_roundscale_round.hpp>
#include <CppSimde/simde_x86_avx512_sad.hpp>
#include <CppSimde/simde_x86_avx512_scalef.hpp>
#include <CppSimde/simde_x86_avx512_set.hpp>
#include <CppSimde/simde_x86_avx512_set1.hpp>
#include <CppSimde/simde_x86_avx512_set4.hpp>
#include <CppSimde/simde_x86_avx512_setr.hpp>
#include <CppSimde/simde_x86_avx512_setr4.hpp>
#include <CppSimde/simde_x86_avx512_setzero.hpp>
#include <CppSimde/simde_x86_avx512_setone.hpp>
#include <CppSimde/simde_x86_avx512_shldv.hpp>
#include <CppSimde/simde_x86_avx512_shuffle.hpp>
#include <CppSimde/simde_x86_avx512_sll.hpp>
#include <CppSimde/simde_x86_avx512_slli.hpp>
#include <CppSimde/simde_x86_avx512_sllv.hpp>
#include <CppSimde/simde_x86_avx512_sqrt.hpp>
#include <CppSimde/simde_x86_avx512_sra.hpp>
#include <CppSimde/simde_x86_avx512_srai.hpp>
#include <CppSimde/simde_x86_avx512_srav.hpp>
#include <CppSimde/simde_x86_avx512_srl.hpp>
#include <CppSimde/simde_x86_avx512_srli.hpp>
#include <CppSimde/simde_x86_avx512_srlv.hpp>
#include <CppSimde/simde_x86_avx512_store.hpp>
#include <CppSimde/simde_x86_avx512_storeu.hpp>
#include <CppSimde/simde_x86_avx512_sub.hpp>
#include <CppSimde/simde_x86_avx512_subs.hpp>
#include <CppSimde/simde_x86_avx512_ternarylogic.hpp>
#include <CppSimde/simde_x86_avx512_test.hpp>
#include <CppSimde/simde_x86_avx512_testn.hpp>
#include <CppSimde/simde_x86_avx512_unpacklo.hpp>
#include <CppSimde/simde_x86_avx512_unpackhi.hpp>
#include <CppSimde/simde_x86_avx512_xor.hpp>
#include <CppSimde/simde_x86_avx512_xorsign.hpp>

#endif

