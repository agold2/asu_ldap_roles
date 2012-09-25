<?php

/**
 * Implementation of hook_rules_defaults().
 */
function asu_ldap_roles_rules_defaults() {
  return array(
    'rules' => array(
      'rules_assign_user_downtown_role_based_on_major_code' => array(
        '#type' => 'rule',
        '#set' => 'event_user_update',
        '#label' => 'Add Downtown role',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'LDAP Roles',
          'asu_ldap_roles' => 'asu_ldap_roles',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#type' => 'OR',
            '#weight' => 0,
            '1' => array(
              '#name' => 'rules_condition_check_boolean',
              '#info' => array(
                'label' => 'Check a truth value',
                'arguments' => array(
                  'boolean' => array(
                    'type' => 'boolean',
                    'label' => 'Truth value',
                  ),
                ),
                'module' => 'Rules',
              ),
              '#settings' => array(
                'boolean' => '<?php return $account->profile_major_code_downtown == NULL; ?>',
                '#eval input' => array(
                  'token_rules_input_evaluator' => array(
                    'boolean' => array(
                      '0' => ':global',
                    ),
                  ),
                  'rules_input_evaluator_php' => array(
                    'boolean' => array(
                      '0' => 'account',
                    ),
                  ),
                ),
              ),
              '#type' => 'condition',
              '#weight' => 0,
            ),
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Add user role',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'User whos roles should be changed',
                ),
              ),
              'module' => 'User',
            ),
            '#name' => 'rules_action_user_addrole',
            '#settings' => array(
              'roles' => array(
                '0' => 12,
              ),
              '#argument map' => array(
                'user' => 'account',
              ),
            ),
            '#type' => 'action',
          ),
          '1' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Show a configurable message on the site',
              'module' => 'System',
              'eval input' => array(
                '0' => 'message',
              ),
            ),
            '#name' => 'rules_action_drupal_message',
            '#settings' => array(
              'message' => '<?php dsm($account); ?>',
              'error' => 0,
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'message' => array(
                    '0' => ':global',
                  ),
                ),
                'rules_input_evaluator_php' => array(
                  'message' => array(
                    '0' => 'account',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
    ),
  );
}