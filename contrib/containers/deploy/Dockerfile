FROM phusion/baseimage:bionic-1.0.0
LABEL maintainer="Akax Developers <dev@akax.tech>"
LABEL description="Dockerised AkaxCore, built from Travis"

ARG USER_ID
ARG GROUP_ID

ENV HOME /akax

# add user with specified (or default) user/group ids
ENV USER_ID ${USER_ID:-1000}
ENV GROUP_ID ${GROUP_ID:-1000}
RUN groupadd -g ${GROUP_ID} akax
RUN useradd -u ${USER_ID} -g akax -s /bin/bash -m -d /akax akax
RUN mkdir /akax/.akaxcore
RUN chown akax:akax -R /akax

COPY bin/* /usr/local/bin/

RUN chmod a+x /usr/local/bin/*

USER akax

VOLUME ["/akax"]

EXPOSE 19191 19190 29291 29290

WORKDIR /akax
