FROM debian:buster

RUN apt -y update
RUN apt -y upgrade

RUN apt install -y nginx mariadb-server php7.3-fpm php7.3-mbstring php7.3-mysql wget vim

RUN mkdir srcs

COPY ./srcs ./srcs
CMD bash srcs/init.sh
