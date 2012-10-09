<?php

/**
 * Implementation of hook_strongarm().
 */
function asu_ldap_roles_strongarm() {
  $export = array();

  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cas_attributes';
  $strongarm->value = array(
    'sync_every_login' => 1,
    'relations' => array(
      'name' => '',
      'mail' => '',
      2 => '[cas-ldap-majorcode]',
      4 => '[cas-ldap-majorcode]',
    ),
    'roles' => array(
      'manage' => array(
        1419717644 => 1419717644,
        1368107126 => 1368107126,
        3519698132 => 0,
        3088675909 => 0,
        3819619309 => 0,
        588493425 => 0,
        3866758342 => 0,
      ),
    ),
    'ldap' => array(
      'server' => 1,
    ),
  );
  $export['cas_attributes'] = $strongarm;

  return $export;
}
