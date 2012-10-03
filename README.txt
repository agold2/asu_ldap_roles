asu_ldap_roles
==============

Use LDAP to give user Downtown role based on major code

Installation:
==============

1) Put this feature in sites/all/modules/custom/

2) Install AND enable LDAP Integration 6.x-beta 2, profile taxonomy_access rules_admin
   * Before enabling this feature download AND enable LDAP Integration.
     + http://ftp.drupal.org/files/projects/ldap_integration-6.x-1.0-beta2.tar.gz
     + Or with Drush:
       $ drush dl  ldap_integration-6.x-1.0-beta2 profile taxonomy_access rules
       $ drush en ldapauth profile taxonomy_access rules_admin
   When this bug (http://drupal.org/node/1742768) is fixed this feature will be
   modified so manual installation shouldn't be necessary, so that enabling the 
   feature with drush will resolve any dependencies.

3) Enable this feature

4) Go to http://drupal_site/admin/settings/ldap/ldapauth/edit/1, scroll all
the way down and input your LDAP APP ID and password.

How the feature works
=====================

LDAP is queried when a user logs in and if the user is a student his or her "major code" is copied
to a profile field. The value of the profile field is checked each time a user account is updated
and if present, a role is added to the user. The Campus taxonomy is used to
grant access to content.

Creates Campus Taxonomy with "Downtown", "Poly", "Tempe", and "West" terms.


Note: Currently only works with Downtown campus. Easy to extend for other
campuses. 

