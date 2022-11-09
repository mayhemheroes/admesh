FROM --platform=linux/amd64 ubuntu:20.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential cmake clang

COPY . /repo
WORKDIR /repo/build
RUN cmake .. -DCMAKE_INSTALL_PREFIX=/install
RUN make -j8
RUN make install
RUN clang++ ../mayhem/fuzz_stl_normalize_vector.cpp -fsanitize=address,fuzzer -I /install/include/admesh/ -L /install/lib/ -ladmesh -o /fuzz

FROM ubuntu:20.04 as package
COPY --from=builder /install /install
COPY --from=builder /fuzz /fuzz_stl_normalize_vector
ENV LD_LIBRARY_PATH=/install/lib
