<?php

/**
 * Implementation of hook_profile_default_profile_fields().
 */
function asu_ldap_roles_profile_default_profile_fields() {
$profile_fields = array();
$profile_fields['profile_major_code'] = array(
  'title' => 'Major Code',
  'name' => 'profile_major_code',
  'explanation' => '',
  'category' => 'asu_ldap_roles',
  'page' => '',
  'type' => 'textfield',
  'weight' => '0',
  'required' => '0',
  'register' => '0',
  'visibility' => '2',
  'autocomplete' => '0',
  'options' => '',
);
return $profile_fields;
}
