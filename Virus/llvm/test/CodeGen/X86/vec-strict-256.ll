; NOTE: Assertions have been autogenerated by utils/update_llc_test_checks.py
; RUN: llc < %s -mtriple=i686-unknown-unknown -mattr=+avx -O3 | FileCheck %s
; RUN: llc < %s -mtriple=x86_64-unknown-unknown -mattr=+avx -O3 | FileCheck %s
; RUN: llc < %s -mtriple=i686-unknown-unknown -mattr=+avx512f -mattr=+avx512vl -O3 | FileCheck %s
; RUN: llc < %s -mtriple=x86_64-unknown-unknown -mattr=+avx512f -mattr=+avx512vl -O3 | FileCheck %s

declare <4 x double> @llvm.experimental.constrained.fadd.v4f64(<4 x double>, <4 x double>, metadata, metadata)
declare <8 x float> @llvm.experimental.constrained.fadd.v8f32(<8 x float>, <8 x float>, metadata, metadata)
declare <4 x double> @llvm.experimental.constrained.fsub.v4f64(<4 x double>, <4 x double>, metadata, metadata)
declare <8 x float> @llvm.experimental.constrained.fsub.v8f32(<8 x float>, <8 x float>, metadata, metadata)
declare <4 x double> @llvm.experimental.constrained.fmul.v4f64(<4 x double>, <4 x double>, metadata, metadata)
declare <8 x float> @llvm.experimental.constrained.fmul.v8f32(<8 x float>, <8 x float>, metadata, metadata)
declare <4 x double> @llvm.experimental.constrained.fdiv.v4f64(<4 x double>, <4 x double>, metadata, metadata)
declare <8 x float> @llvm.experimental.constrained.fdiv.v8f32(<8 x float>, <8 x float>, metadata, metadata)

define <4 x double> @f1(<4 x double> %a, <4 x double> %b) #0 {
; CHECK-LABEL: f1:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vaddpd %ymm1, %ymm0, %ymm0
; CHECK-NEXT:    ret{{[l|q]}}
  %ret = call <4 x double> @llvm.experimental.constrained.fadd.v4f64(<4 x double> %a, <4 x double> %b,
                                                                     metadata !"round.dynamic",
                                                                     metadata !"fpexcept.strict") #0
  ret <4 x double> %ret
}

define <8 x float> @f2(<8 x float> %a, <8 x float> %b) #0 {
; CHECK-LABEL: f2:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vaddps %ymm1, %ymm0, %ymm0
; CHECK-NEXT:    ret{{[l|q]}}
  %ret = call <8 x float> @llvm.experimental.constrained.fadd.v8f32(<8 x float> %a, <8 x float> %b,
                                                                    metadata !"round.dynamic",
                                                                    metadata !"fpexcept.strict") #0
  ret <8 x float> %ret
}

define <4 x double> @f3(<4 x double> %a, <4 x double> %b) #0 {
; CHECK-LABEL: f3:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vsubpd %ymm1, %ymm0, %ymm0
; CHECK-NEXT:    ret{{[l|q]}}
  %ret = call <4 x double> @llvm.experimental.constrained.fsub.v4f64(<4 x double> %a, <4 x double> %b,
                                                                     metadata !"round.dynamic",
                                                                     metadata !"fpexcept.strict") #0
  ret <4 x double> %ret
}

define <8 x float> @f4(<8 x float> %a, <8 x float> %b) #0 {
; CHECK-LABEL: f4:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vsubps %ymm1, %ymm0, %ymm0
; CHECK-NEXT:    ret{{[l|q]}}
  %ret = call <8 x float> @llvm.experimental.constrained.fsub.v8f32(<8 x float> %a, <8 x float> %b,
                                                                    metadata !"round.dynamic",
                                                                    metadata !"fpexcept.strict") #0
  ret <8 x float> %ret
}

define <4 x double> @f5(<4 x double> %a, <4 x double> %b) #0 {
; CHECK-LABEL: f5:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vmulpd %ymm1, %ymm0, %ymm0
; CHECK-NEXT:    ret{{[l|q]}}
  %ret = call <4 x double> @llvm.experimental.constrained.fmul.v4f64(<4 x double> %a, <4 x double> %b,
                                                                     metadata !"round.dynamic",
                                                                     metadata !"fpexcept.strict") #0
  ret <4 x double> %ret
}

define <8 x float> @f6(<8 x float> %a, <8 x float> %b) #0 {
; CHECK-LABEL: f6:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vmulps %ymm1, %ymm0, %ymm0
; CHECK-NEXT:    ret{{[l|q]}}
  %ret = call <8 x float> @llvm.experimental.constrained.fmul.v8f32(<8 x float> %a, <8 x float> %b,
                                                                    metadata !"round.dynamic",
                                                                    metadata !"fpexcept.strict") #0
  ret <8 x float> %ret
}

define <4 x double> @f7(<4 x double> %a, <4 x double> %b) #0 {
; CHECK-LABEL: f7:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vdivpd %ymm1, %ymm0, %ymm0
; CHECK-NEXT:    ret{{[l|q]}}
  %ret = call <4 x double> @llvm.experimental.constrained.fdiv.v4f64(<4 x double> %a, <4 x double> %b,
                                                                     metadata !"round.dynamic",
                                                                     metadata !"fpexcept.strict") #0
  ret <4 x double> %ret
}

define <8 x float> @f8(<8 x float> %a, <8 x float> %b) #0 {
; CHECK-LABEL: f8:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vdivps %ymm1, %ymm0, %ymm0
; CHECK-NEXT:    ret{{[l|q]}}
  %ret = call <8 x float> @llvm.experimental.constrained.fdiv.v8f32(<8 x float> %a, <8 x float> %b,
                                                                    metadata !"round.dynamic",
                                                                    metadata !"fpexcept.strict") #0
  ret <8 x float> %ret
}

attributes #0 = { strictfp }