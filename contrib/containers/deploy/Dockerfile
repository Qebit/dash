FROM phusion/baseimage:bionic-1.0.0
LABEL maintainer="Xeke Developers <dev@xeke.tech>"
LABEL description="Dockerised XekeCore, built from Travis"

ARG USER_ID
ARG GROUP_ID

ENV HOME /xeke

# add user with specified (or default) user/group ids
ENV USER_ID ${USER_ID:-1000}
ENV GROUP_ID ${GROUP_ID:-1000}
RUN groupadd -g ${GROUP_ID} xeke
RUN useradd -u ${USER_ID} -g xeke -s /bin/bash -m -d /xeke xeke
RUN mkdir /xeke/.xekecore
RUN chown xeke:xeke -R /xeke

COPY bin/* /usr/local/bin/

RUN chmod a+x /usr/local/bin/*

USER xeke

VOLUME ["/xeke"]

EXPOSE 19191 19190 29291 29290

WORKDIR /xeke
