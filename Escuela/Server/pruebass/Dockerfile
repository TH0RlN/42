# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/21 10:54:01 by rarias-p          #+#    #+#              #
#    Updated: 2020/11/10 19:12:32 by rarias-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt update
RUN apt install vim mariadb-server php7.3-fpm php7.3-mbstring php7.3-mysql nginx wget -y

RUN mkdir srcs

COPY ./srcs/wordpress.sql ./srcs

COPY ./srcs/config.inc.php ./srcs
COPY ./srcs/wp-config.php ./srcs
#COPY ./srcs/wordpress ./var/www/html/wordpress
RUN rm /etc/nginx/sites-enabled/default

RUN mkdir /etc/nginx/ssl
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/localhost.key -out /etc/ssl/certs/localhost.crt -subj "/C=ES/ST=Galicia/L=Vigo/O=42MadridFTef/OU=rarias-p/CN=localhost"
RUN openssl dhparam -out /etc/ssl/certs/localhost.pem 2048

COPY ./srcs/default ./etc/nginx/sites-enabled
COPY ./srcs/start.sh ./
CMD bash start.sh