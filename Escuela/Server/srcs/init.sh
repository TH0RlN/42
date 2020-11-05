#!/bin/bash

wget -P var/www/html https://files.phpmyadmin.net/phpMyAdmin/4.9.5/phpMyAdmin-4.9.5-all-languages.tar.gz
tar -xvf var/www/html/phpMyAdmin-4.9.5-all-languages.tar.gz
rm var/www/html/phpMyAdmin-4.9.5-all-languages.tar.gz
mv phpMyAdmin-4.9.5-all-languages/ phpmyadmin
mv var/www/html/phpmyadmin/config.sample.inc.php var/www/html/phpmyadmin/config.inc.php

wget -P var/www/html https://es.wordpress.org/latest-es_ES.tar.gz
tar -xvf var/www/html/latest-es_ES.tar.gz
rm var/www/html/latest-es_ES.tar.gz
mv var/www/html/wordpress/wp-config-sample.php var/www/html/wordpress/wp-config.php

mv srcs/default etc/nginx/sites-available/default

service mysql start
echo "CREATE DATABASE wordpress;" | mysql -u root
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost';" | mysql -u root
echo "FLUSH PRIVILEGES;" | mysql -u root
echo "update mysql.user set plugin = 'mysql_native_password' where user='root';" | mysql -u root

service nginx start
service php7.3-fpm start
service mysql restart

chown -R www-data:www-data /var/www/*
chomd -R 755 /var/www/*

service nginx restart
service php7.3-fpm restart
service mysql restart

bash
