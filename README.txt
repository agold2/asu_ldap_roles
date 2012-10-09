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
       $ drush dl  ldap_integration-6.x-1.0-beta2 taxonomy_access role_export
       $ drush en ldapauth profile taxonomy_access
   When this bug (http://drupal.org/node/1742768) is fixed this feature will be
   modified so manual installation shouldn't be necessary, so that enabling the 
   feature with drush will resolve any dependencies.

3) Apply patches to features and role_export. Insructions on how to apply patches:
   http://drupal.org/patch/apply
     If you are in this feature's directory:
       patch -p1 path/to/features/features.module < features-profile-fields-912716-23.patch
       patch -p1 path/to/role_export/role_export.module < role_export-update_permissions_and_users_roles_tables_with_new_rid-1794490-1.patch

4) Enable this feature

5) Go to http://drupal_site/admin/settings/ldap/ldapauth/edit/1, scroll all
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
