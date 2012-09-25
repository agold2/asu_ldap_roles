asu_ldap_roles
==============

Use LDAP to give user Downtown role based on major code

Installation:
==============

* Put this feature somewhere in /sites/all/modules/

* Prior to enabling this feature download the LDAP Integration module, version  6.x-1.0-beta2.
  + Download: http://ftp.drupal.org/files/projects/ldap_integration-6.x-1.0-beta2.tar.gz
  + Or with Drush:
      drush dl  ldap_integration-6.x-1.0-beta2
      drush en ldapauth
When this bug (http://drupal.org/node/1742768) is fixed this feature will be modified so manual 
installation shouldn't be necessary, so that enabling the feature with drush will resolve any dependencies.

How the feature works
=====================

LDAP is queried when a user logs in and if the user is a student his or her "major code" is copied
to a profile field. The value of the profile field is checked each time a user account is updated
and if present, a role is added to the user.


