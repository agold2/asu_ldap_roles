asu_ldap_roles
==============

Use LDAP to give user Downtown role based on major code

Installation:
==============

1) IMPORTANT: Please backup your database before trying this out.

2) Put this feature in sites/all/modules/custom/. Do not enable until step 5.

3) Install AND enable LDAP Integration 6.x-beta 2, profile taxonomy_access rules_admin
  
     + http://ftp.drupal.org/files/projects/ldap_integration-6.x-1.0-beta2.tar.gz
     + Or with Drush:
       $ drush dl  ldap_integration-6.x-1.0-beta2 taxonomy_access role_export
       $ drush en ldapauth profile taxonomy_access
   When this bug (http://drupal.org/node/1742768) is fixed this feature will be
   modified so manual installation of ldap_integration shouldn't be necessary.

4) Apply patch to role_export. If you are in this feature's directory:
     patch -p1 path/to/role_export/role_export.module < role_export-update_permissions_and_users_roles_tables_with_new_rid-1794490-1.patch

5) Enable this feature

6) Go to http://drupal_site/admin/settings/ldap/ldapauth/edit/1, scroll all
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


Troubleshooting: 
===============

On our site CKeditor was being loaded on some admin config pages. We needed to exclude the following
paths at https://eoss-qa.asu.edu/admin/settings/ckeditor/editg
seven:admin/user/cas/settings.edit-cas-pages
seven:admin/user/cas/settings.edit-cas-exclude
seven:admin/settings/ldap/ldapauth/edit/1.edit-basedn
seven:admin/user/profile/edit/1.edit-options
