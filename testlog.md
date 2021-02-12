# Some Test Log

***

# Version:0.1.3
## Mifare
### Card Info
+ Official, Mifare card: Passed
+ Iceman, Mifare card: Passed
+ Official, no card: Passed
+ Iceman, no card: Passed

### Check default Password
+ Official, all FFFFFFFFFFFF: Passed
+ Iceman, all FFFFFFFFFFFF: Passed
+ Official, no card: Passed
+ Iceman, no card: Stuck to searching card, then failed to communicate with PM3
+ Official, all unknown: Passed
+ Iceman, all unknown: Passed
+ Official, partially unknown: Passed
+ Iceman, partially unknown: Passed

### Darkside Attack
+ Official: Passed
+ Iceman: Passed