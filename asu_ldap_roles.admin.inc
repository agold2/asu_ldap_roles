<?php
// $Id: 

/**
 * @file
 * Module admin page callbacks.
 */

//////////////////////////////////////////////////////////////////////////////
// Major codes

/**
 * Implements the settings page.
 *
 * @return
 *   The form structure.
 */
function asu_ldap_roles_admin_settings() {

  $form['system_options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Major Codes'),
    //'#description' => t('These settings...'),
    //'#collapsible' => TRUE,
    //'#collapsed' => FALSE,
  );
  //$default_downtown_majorcodes = implode("\n", variable_get('asu_ldap_roles_downtown_majorcodes'));
  $downtown = variable_get('asu_ldap_roles_downtown', '');
  $form['system_options']['asu_ldap_roles_downtown'] = array(
    '#type' => 'textarea',
    '#title' => t('Downtown Major Codes'),
    '#default_value' => $downtown,
    '#cols' => 60,
    '#rows' => 5,
    '#description' => t('Enter one major code per line'),
  );
  $tempe = variable_get('asu_ldap_roles_tempe', '');
  $form['system_options']['asu_ldap_roles_tempe'] = array(
    '#type' => 'textarea',
    '#title' => t('Tempe Major Codes'),
    '#default_value' => $tempe,
    '#cols' => 60,
    '#rows' => 5,
    '#description' => t('Enter one major code per line'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Configuration'),
  );

  return $form;
}

/**
 * Submit hook for the settings form.
 */
function asu_ldap_roles_admin_settings_submit($form, &$form_state) {
  $op = $form_state['clicked_button']['#value'];
  $values = $form_state['values'];
  switch ($op) {
    case t('Save Configuration'):
      //$downtown_major_codes = array();
      //$downtown_major_codes = explode("\n", $values['asu_ldap_roles_downtown_majorcodes']);
      $downtown = trim($values['asu_ldap_roles_downtown']);
      $tempe = trim($values['asu_ldap_roles_tempe']);
      
      variable_set('asu_ldap_roles_downtown', $downtown);
      variable_set('asu_ldap_roles_tempe', $tempe);
      drupal_set_message(t('The configuration options have been saved.'));
      break;
    case t('Reset to defaults'):
      //variable_del('asu_ldap_roles_downtown_majorcodes');

      drupal_set_message(t('The configuration options have been reset to their default values.'));
      break;
  }

  // Rebuild the menu router.
  menu_rebuild();
}

