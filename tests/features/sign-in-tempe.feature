Feature: NYT Downtown
  In order to view NYT page
    As a Tempe student
    I need to view NYT page
Scenario: Visits 
  Given I am on "/nyt"
    When I fill in "ASURITE User ID" with "temp5827"
    And I fill in "Password" with "Za5tyRf1PmCx69jV"
    And I press "Sign In"
  Then I should see "contact Ronald Briggs"
