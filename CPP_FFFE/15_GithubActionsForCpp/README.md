![Title slide for CPP_Friends#15](...)
# Github Actions
This is the 15th meeting in the CPP\_Friends series, where the subject of continuous integration is introduced.
I aim to demonstrate how simple it is to just get started with using CI/CD pipelines for projects hosted on Github.

# Talk plan
The aim of this talk is to have a simple CI system which runs unit tests after each commit is pushed to the `main` branch.
This is done via the following steps:

1. Set up a new public github repository
2. Introduce googletest as a submodule
3. Add initial build rules (CMake), plus some code and some tests
4. Set up the CI pipeline via .github/workflows/firstAction.yml
5. Test the pipeline by committing some changes

Will be carried out on January 28, 2022.
