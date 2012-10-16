<?php

use Behat\Symfony2Extension\Context\KernelAwareInterface;
use Behat\MinkExtension\Context\MinkContext;
use Behat\Behat\Context\ClosuredContextInterface,
    Behat\Behat\Context\TranslatedContextInterface,
    Behat\Behat\Context\BehatContext,
    Behat\Behat\Exception\PendingException;
use Behat\Gherkin\Node\PyStringNode,
	Behat\Gherkin\Node\TableNode;

require_once 'vendor/autoload.php';

//
// Require 3rd-party libraries here:
//
//   require_once 'PHPUnit/Autoload.php';
//   require_once 'PHPUnit/Framework/Assert/Functions.php';
//

/**
 * Features context.
 */

class FeatureContext extends MinkContext
{
    /** @BeforeFeature */
    public static function prepareForTheFeature() {
    // clean database or do other preparation stuff
    }
 
    /**
    * @Given /^I am on the homepage$/
    */
    public function iAmOnTheHomepage() {
       $this->getSession()->visit($this->locatePath('/'));
    }


  /**
   * Authenticates a user. This is both a Given and a utility function.
   *
   * @Given /^I am logged in as "([^""]*)" at the path "([^""]*)"$/
   */
  public function iAmLoggedInAsAtThePath($username, $path) {
    // Go to specified path
    $this->getSession()->visit($this->locatePath($path));
    $password = $this->fetchPassword($username);
    $this->fillField('username', $username);
    $this->fillField('password', $password);
    $this->pressButton('Sign In');
    //if (empty($submit)) {
    //  throw new \Exception('No submit button at ' . $this->getSession()->getCurrentUrl());
   // }

    // Log in.
    //$submit->click();

    return;
  }

 /**
   * Helper function to fetch user passwords stored in behat.local.yml.
   *
   * @param string $name
   *   The username to fetch the password for.
   *
   * @return string
   *   The matching password or FALSE on error.
   */
  public function fetchPassword($name) {
    $property_name = 'drupal_users';
    try {
      $property = $this->$property_name;
      $password = $property[$name];
      return $password;
    } catch (Exception $e) {
      throw new Exception("Non-existent user/password for $property_name:$name please check behat.local.yml.");
    }
  }





    /**
     * Initializes context.
     *
     * Every scenario gets its own context object.
     *
     * @param array $parameters.
     *   Context parameters (set them up through behat.yml or behat.local.yml).
     */
    public function __construct(array $parameters) {
      if (isset($parameters['drupal_users'])) {
        $this->drupal_users = $parameters['drupal_users'];
      }
    }

}
