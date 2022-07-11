#!/bin/bash
# coding=utf-8

set -euo pipefail

cwd="$(dirname "$(realpath "$0")")"
grpc_root="${GRPC_ROOT:-/opt/grpc_v1.24.3}"

PROTOC="${PROTOC:-${grpc_root}/build/third_party/protobuf/protoc}"
PLUGIN="--plugin=protoc-gen-grpc=${GRPC_PLUGIN:-${grpc_root}/build/grpc_cpp_plugin}"

[ ! -x "$(command -v "${PROTOC}" 2> /dev/null)" ] \
	&& echo "${PROTOC}: executable not found" \
	&& exit 1

echo "Generating sarmata C++ protobuf/grpc sources..."
path_i="${cwd}/../proto"
path_o="${cwd}/libsarmata-client"
${PROTOC} \
	-I"${path_i}" \
	"${PLUGIN}" \
	--cpp_out="${path_o}" \
	--grpc_out="${path_o}" \
	"${path_i}/sarmata_asr.proto"
