Feature: NYT Downtown
  In order to view NYT page
    As a Downtown student
    I need to view NYT page
Scenario: Visits 
  Given I am logged in as "temp5826" at the path "/nyt" 
  Then I should see "FAQ"
