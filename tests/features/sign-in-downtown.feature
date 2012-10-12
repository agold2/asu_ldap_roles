Feature: NYT Downtown
  In order to view NYT page
    As a Downtown student
    I need to view NYT page
Scenario: Visits 
  Given I am on "/nyt"
    When I fill in "ASURITE User ID" with "temp5826"
    And I fill in "Password" with "EpFU/%M4YJax!V0!"
    And I press "Sign In"
  Then I should see "FAQ"
