# LLVM 15 runtime smoke test

Build `llvm15-runtime.cpp` as a Darwin executable with the candidate libc++
headers, C++20, exceptions enabled, and both candidate libc++/libc++abi libraries.
Run it inside Darling with those two libraries installed in an isolated prefix.
Do not compile with NDEBUG: the assertions are part of the test.

Require exit zero and:

    PASS: merged libcxx allocation, exception RTTI and filesystem iteration

The test covers vector/string allocation, runtime_error with base-class catch
and what(), out_of_range unwinding, directory status and iteration. It is a
smoke test, not an exhaustive libc++ conformance/ABI test or an x86 validation.

Validation on Linux ARM64: all 47 libc++ and 18 libc++abi translation units were
compiled using staged Darling target recipes with candidate headers. Both
libraries linked and this test passed in an isolated known-working guest root
with the candidate libraries and merged darlingserver mounted read-only.
Other dependencies remained staged; a clean full-tree CMake build was not run.

The libc++abi companion build changes are needed to compile the existing ABI
implementation against LLVM 15 headers. Upstream typed allocation overloads
and filesystem source selection are retained.
