#include <stdint.h>
#include <stdio.h>
#include <climits>
#include "stl.h"

#include <fuzzer/FuzzedDataProvider.h>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider provider(data, size);
    float a = provider.ConsumeFloatingPoint<float>();
    float b = provider.ConsumeFloatingPoint<float>();
    float c = provider.ConsumeFloatingPoint<float>();
    float v[3] = {a, b, c};

    stl_normalize_vector(v);
    return 0;
}