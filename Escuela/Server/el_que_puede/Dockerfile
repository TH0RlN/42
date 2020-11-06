# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/21 10:54:01 by rarias-p          #+#    #+#              #
#    Updated: 2020/11/06 17:43:18 by rarias-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt update
RUN apt install vim mariadb-server php7.3-fpm php7.3-mbstring php7.3-mysql nginx wget -y

RUN mkdir srcs

COPY ./srcs/config.inc.php ./srcs
COPY ./srcs/wp-config.php ./srcs
RUN rm /etc/nginx/sites-enabled/default

COPY ./srcs/default ./etc/nginx/sites-enabled
COPY ./srcs/start.sh ./
CMD bash start.sh