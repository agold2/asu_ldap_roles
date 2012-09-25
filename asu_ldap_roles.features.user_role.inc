<?php

/**
 * Implementation of hook_user_default_roles().
 */
function asu_ldap_roles_user_default_roles() {
  $roles = array();

  // Exported role: Downtown
  $roles['Downtown'] = array(
    'name' => 'Downtown',
  );

  // Exported role: Tempe
  $roles['Tempe'] = array(
    'name' => 'Tempe',
  );

  return $roles;
}
