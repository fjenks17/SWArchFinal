# Requirements:
We decided the default requirements were sufficient for the project, as we don't know what else we'd add to them.

Requirement 1 (REQUIRED) – All core Observer services should be in libcore 

Requirement 2 (REQUIRED) – Application specific portions of Observer should be in appropriate libraries (i.e. not libcore) 

Requirement 3 (REQUIRED) – Need to have a High level Session object. So application specific observers are not registered on CoreSession. 

Requirement 4 (Required) – Implement a second use case for observers to show that core functionality is isolated, but can be extensible. 

# Initial Estimate:

We believe that this project will take around 30 hours of work.

### [Design Diagram](../main/DesignDiagram.md)

# Conclusions

We do not feel that we have fully accomplished what we set out to do. However, we believe that we have made significant progress towards meeting our requirements and with a bit more time we would be able to finish what we've started. On top of fulfilling the current requirements, we would plan to rework the original observer even further to improve extensibility even more. 
