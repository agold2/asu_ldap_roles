<?php

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function asu_ldap_roles_taxonomy_default_vocabularies() {
  return array(
    'campus' => array(
      'name' => 'Campus',
      'description' => 'To which campus does this content belong?',
      'help' => '',
      'relations' => '1',
      'hierarchy' => '1',
      'multiple' => '1',
      'required' => '0',
      'tags' => '0',
      'module' => 'features_campus',
      'weight' => '0',
      'nodes' => array(
        'fixed_width_landing_page' => 'fixed_width_landing_page',
      ),
    ),
  );
}
