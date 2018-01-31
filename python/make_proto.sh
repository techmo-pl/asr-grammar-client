#!/usr/bin/env bash

echo "Generating Techmo ASR Sarmata - python protobuf/grpc sources."
path_i="../proto/"
path_o="service/"
python3 -m grpc_tools.protoc \
	        -I${path_i} \
            --python_out=${path_o} \
            --grpc_python_out=${path_o} \
            ${path_i}/asr_service.proto

# Fix buggy autogenerated GRPC import
sed -i 's/import asr_service_pb2 as asr__service__pb2/from . import asr_service_pb2 as asr__service__pb2/' ${path_o}/asr_service_pb2_grpc.py
