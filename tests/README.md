# How to Run Tests

##One Time Setup
* Download Selenium Server: http://docs.seleniumhq.org/download
* Download and install Behat, Mink & dependencies:
$ curl http://getcomposer.org/installer | php
$ php composer.phar install

# Run test suite:
* Run Selenium Server: 
$ java -jar selenium-server-standalone-XXX.jar
* Run Behat
$ bin/behat
