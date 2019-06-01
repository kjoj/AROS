# AROS Git Repository

> This is the main repository for active development of the AROS Operating System.
> The repository contains the main Operating System components, SDK and Build System.


## Nightly Test Builds


* All builds are scheduled to run at 00:00 UTC.
* The builds are made using the scripts/azure-pipelines.yml file. Further details can be found in that file.
* Currently all builds are configured to use gcc 9.1.0.
* The main AROS target and distfiles are built for each arch.
* The builds are downloadable via http://www.aros.org/nightly1.php.


| BUILD Arch | Status |
| --- | --- |
| amiga-m68k | [![Build Status](https://dev.azure.com/aros-development-team/AROS/_apis/build/status/aros-development-team.AROS-amiga-m68k?branchName=master)](https://dev.azure.com/aros-development-team/AROS/_build/latest?definitionId=1&branchName=master) |
| pc-i386 | [![Build Status](https://dev.azure.com/aros-development-team/AROS/_apis/build/status/aros-development-team.AROS-pc-i386?branchName=master)](https://dev.azure.com/aros-development-team/AROS/_build/latest?definitionId=1&branchName=master) |
| pc-x86_64 | [![Build Status](https://dev.azure.com/aros-development-team/AROS/_apis/build/status/aros-development-team.AROS-pc-x86_64?branchName=master)](https://dev.azure.com/aros-development-team/AROS/_build/latest?definitionId=1&branchName=master) |
| pc-x86_64-smp | [![Build Status](https://dev.azure.com/aros-development-team/AROS/_apis/build/status/aros-development-team.AROS-pc-x86_64-smp?branchName=master)](https://dev.azure.com/aros-development-team/AROS/_build/latest?definitionId=7&branchName=master) |
| raspi-armhf | [![Build Status](https://dev.azure.com/aros-development-team/AROS/_apis/build/status/aros-development-team.AROS-raspi-armhf?branchName=master)](https://dev.azure.com/aros-development-team/AROS/_build/latest?definitionId=1&branchName=master) |
| sam440-ppc | [![Build Status](https://dev.azure.com/aros-development-team/AROS/_apis/build/status/aros-development-team.AROS-sam440-ppc?branchName=master)](https://dev.azure.com/aros-development-team/AROS/_build/latest?definitionId=1&branchName=master) |
| linux-i386 | [![Build Status](https://dev.azure.com/aros-development-team/AROS/_apis/build/status/aros-development-team.AROS-linux-i386?branchName=master)](https://dev.azure.com/aros-development-team/AROS/_build/latest?definitionId=1&branchName=master) |
| linux-x86_64 | [![Build Status](https://dev.azure.com/aros-development-team/AROS/_apis/build/status/aros-development-team.AROS-linux-x86_64?branchName=master)](https://dev.azure.com/aros-development-team/AROS/_build/latest?definitionId=1&branchName=master) |
| darwin-x86_64 | [![Build Status](https://dev.azure.com/aros-development-team/AROS/_apis/build/status/aros-development-team.AROS-darwin-x86_64?branchName=master)](https://dev.azure.com/aros-development-team/AROS/_build/latest?definitionId=1&branchName=master) |


## License

This project is licensed under the APL License - see the [LICENSE](LICENSE) file for details

## Acknowledgments

AROS contains parts built upon external components - see the [ACKNOWLEDGEMENTS](ACKNOWLEDGEMENTS) file for details

