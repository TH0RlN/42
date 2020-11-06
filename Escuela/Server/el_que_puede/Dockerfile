# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/21 10:54:01 by rarias-p          #+#    #+#              #
#    Updated: 2020/09/24 21:10:45 by rarias-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:buster

RUN apt update
RUN apt install vim mariadb-server php7.3-fpm php7.3-mbstring php7.3-mysql nginx wget -y

COPY ./src/phpmyadmin ./var/www/html/phpmyadmin
COPY ./src/wordpress ./var/www/html/wordpress

RUN rm /etc/nginx/sites-enabled/default

COPY ./src/default ./etc/nginx/sites-enabled
COPY ./src/start.sh ./
CMD bash start.sh