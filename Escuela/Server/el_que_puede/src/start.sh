#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    start.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/22 11:56:09 by rarias-p          #+#    #+#              #
#    Updated: 2020/09/22 11:57:21 by rarias-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

mkdir /etc/nginx/ssl
openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/localhost.key -out /etc/ssl/certs/localhost.crt -subj "/C=ES/ST=Galicia/L=Vigo/O=42MadridFTef/OU=rarias-p/CN=localhost"
openssl dhparam -out /etc/ssl/certs/localhost.pem 2048
service mysql start
echo "CREATE DATABASE wordpress;" | mysql
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;" | mysql
echo "update mysql.user set plugin='mysql_native_password' where user='root';" | mysql
echo "FLUSH PRIVILEGES;" | mysql
service nginx start
service php7.3-fpm start
chown -R www-data:www-data /var/www/*
chmod -R 755 /var/www/*
service mysql restart
service nginx restart
service php7.3-fpm restart
bash