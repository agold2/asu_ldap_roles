Feature: NYT Tempe
  In order to view NYT page
    As a Tempe student
    I need to see Access Denied
Scenario: Visits 
  Given I am logged in as "temp5827" at the path "/nyt"
  # When I fill in "ASURITE User ID" with "temp5827"
  #  And I fill in "Password" with "Za5tyRf1PmCx69jV"
  #  And I press "Sign In"
  Then I should see "contact Ronald Briggs"
