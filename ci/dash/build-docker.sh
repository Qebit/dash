#!/usr/bin/env bash

export LC_ALL=C

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd "$DIR"/../.. || exit

DOCKER_IMAGE=${DOCKER_IMAGE:-akaxpay/akaxd-develop}
DOCKER_TAG=${DOCKER_TAG:-latest}
DOCKER_RELATIVE_PATH=contrib/containers/deploy

BUILD_DIR=${BUILD_DIR:-.}


if [ -d $DOCKER_RELATIVE_PATH/bin ]; then
    rm $DOCKER_RELATIVE_PATH/bin/*
fi

mkdir $DOCKER_RELATIVE_PATH/bin
cp "$BUILD_DIR"/src/akaxd    $DOCKER_RELATIVE_PATH/bin/
cp "$BUILD_DIR"/src/akax-cli $DOCKER_RELATIVE_PATH/bin/
cp "$BUILD_DIR"/src/akax-tx  $DOCKER_RELATIVE_PATH/bin/
strip $DOCKER_RELATIVE_PATH/bin/akaxd
strip $DOCKER_RELATIVE_PATH/bin/akax-cli
strip $DOCKER_RELATIVE_PATH/bin/akax-tx

docker build --pull -t "$DOCKER_IMAGE":"$DOCKER_TAG" -f $DOCKER_RELATIVE_PATH/Dockerfile docker
