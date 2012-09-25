<?php

/**
 * Implementation of hook_role_export_defaults().
 */
function asu_ldap_roles_role_export_defaults() {
  $roles = array();

  $roles['downtown'] = array(
    'rid' => '1419717644',
    'name' => 'Downtown',
    'machine_name' => 'downtown',
  );

  $roles['tempe'] = array(
    'rid' => '1368107126',
    'name' => 'Tempe',
    'machine_name' => 'tempe',
  );

  return $roles;
}
