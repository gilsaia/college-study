PostgreSQL

    Develop Performance Farm Database and Website (2019)
    Project Description
    The PostgreSQL Performance Farm project is a community project to collect performance data from tests as code changes are made to PostgreSQL. To support this effort, a database needs to be created for storing results, and a Web site developed to review results. This project will focus on developing the Web site on top of the database.

    The database will be using PostgreSQL in the back-end. Test results will come in the form of JSON and flat files. The Web application will be developed using the Django Web framework.

    For reference, the code that will be supplying test results is https://git.postgresql.org/gitweb/?p=pgperffarm.git;a=summary.

    As an example, the PostgreSQL Build Farm site [1] is a central repository for the results of testing source code changes for PostgreSQL as they occur, on a wide variety of platforms.

    Skills needed
    Python programming
    SQL programming
    Difficulty Level
    This project requires familiarity with Python programming and basic database experience.

    Potential Mentors
    Mark Wong can mentor.
    Andreas Scherbaum can mentor.
    Pavan Agrawal can mentor.
    Expected Outcomes
    A functional Web site where clients can upload test results, and users can search and review uploaded results.
    References
    [1] https://buildfarm.postgresql.org/

Hydra Ecosystem

    1. Improvement/Additions to the Parsers:
    Main Idea:
    A lot of things haven’t been implemented in the OpenAPI parser or did not have alternatives in Hydra. With the updations in the spec for both, there might be workarounds for this. We also would like to implement more such parsers and have a general collection of them to help people using different specs adopt Hydra easily. One such possibility is RAML. More such API definition specs need to be identified and tools should be created for migration to Hydra.

    Skills Required:

    Python
    Hydra
    hydrus
    REST
    Difficulty Level: Intermediate

    Issues 
    We are currently porting the Hydra-OpenAPI Parser to be a standalone library outside of hydrus’ codebase, work in progress here. The first tasks will be to complete the porting and then working on this repository. Other parsers to Hydra can be proposed.
    1. Django port for hydrus.
    Main Idea:
    hydrus is developed in Flask because the applications we had in mind were mostly related to IoT and sensors, so it was supposed to be lightweight and functional. But if we may want to look for more traditional applications and the wider public, we may like to have a Django library that does have the same features as hydrus but works with Django. As Django has already a well-established REST library (Django-rest) it would be probably useful to extend it and create something like Django-rest-hydra, a library that let Django developers deploy hydra server in Django as now hydrus does with flask (starting from an API Documentation or an OpenAPI definition).

    Skill Required:
    Python
    Django
    hydrus
    Hydra
    Ability to write test suites in Django
    Difficulty Level: Intermediate

CBMI@UTHSC

    Project 1: React-based web application for sepsis detection
    Description: Sepsis is a life-threatening condition with high mortality rates. Early detection and treatment are critical to improving outcomes. Our goal is to develop an open source artificial intelligence based alert system capable of predicting sepsis earlier using only a minimal set of streaming physiological data in real-time. Using physiologic data of adult patients from the intensive care unit, we already developed a Python-based machine learning method and would like to extend this work and develop an open-source react based front-end application. In addition to the sepsis prediction pipeline, the application would also have a visualization component for time_to_sepsis development.

    Required skills: Python, React, Machine learning, Flask, Nginx
    Potential Mentors: Akram Mohammed, Rishikesan Kamaleswaran, Anahita Khojandi
    Difficulty Rating: Medium

    Project 2: Python-based standalone application for sickle cell disease prediction
    Description: Sickle cell disease (SCD) is a genetic disorder of the red blood cells, resulting in multiple acute and chronic complications including pain crises, stroke, and kidney disease. Patients with SCD develop chronic organ dysfunction that may progress to organ failure, but early detection of acute physiological deterioration leading to organ failure is not always attainable. Machine learning techniques that allow for prediction of organ failure from physio markers may enable earlier identification and treatment, and potentially reduce mortality. The project would also have the capability to predict the order of organ failure over a period of time. 

    Required skills: Python, Machine learning
    Potential Mentors: Akram Mohammed, Rishikesan kamaleswaran
    Difficulty Rating: Easy

Bazel

    Sandboxing on Windows
    Description: Bazel on Linux already supports various ways to run actions in a sandbox (linux-sandbox, processwrapper-sandbox). We want to support sandboxing on Windows too.

    Design and implement a way to execute actions in a sandbox on Windows, and integrate it with Bazel.

    We recommend using Microsoft Build Accelerator's example project as the foundation.

    Related issue: https://github.com/bazelbuild/bazel/issues/5136

    Knowledge prerequisite: Experience with C/C++ and Windows API programming. Knowing Java is a plus, knowing Detours or the aforementioned Microsoft Build Accelerator example project and its inner workings is a big plus.

    Mentor: laszlocsomor (at google.com)


Dear all,

As you start to explore the dataset and methods, please be sure to read the following papers to get a better idea of what work has already been done:

Deep Learning:
1. https://www.researchgate.net/publication/322703262_A_robust_deep_convolutional_neural_network_for_the_classification_of_abnormal_cardiac_rhythm_using_varying_length_single_lead_electrocardiogram

2. https://www.researchgate.net/publication/322219344_How_much_data_should_we_collect_A_case_study_in_sepsis_detection_using_deep_learning

Sepsis:

1. https://www.researchgate.net/profile/Vasilios_Papaioannou/publication/258035722_Temperature_multiscale_entropy_analysis_A_promising_marker_for_early_prediction_of_mortality_in_septic_patients

2. https://www.researchgate.net/profile/Rishikesan_Kamaleswaran/publication/330596816_Improving_Prediction_Performance_Using_Hierarchical_Analysis_of_Real-Time_Data_A_Sepsis_Case_Study

3. https://www.researchgate.net/publication/326661039_Applying_Artificial_Intelligence_to_Identify_Physiomarkers_Predicting_Severe_Sepsis_in_the_PICU

Spark and ML:

1. https://www.researchgate.net/publication/324903240_PhysOnline_An_Online_Feature_Extraction_and_Machine_Learning_Pipeline_for_Real-Time_Analysis_of_Streaming_Physiological_Data

Fever: 

1. https://www.researchgate.net/publication/330063912_46_MACHINE_LEARNING_APPLIED_TO_CONTINUOUS_PHYSIOLOGIC_DATA_PREDICTS_FEVER_IN_CRITICALLY_ILL_CHILDREN

For web based applications please review:

1. https://www.researchgate.net/publication/310662904_A_Review_of_Visual_Representations_of_Physiologic_Data
2. https://www.researchgate.net/publication/304811433_PhysioEx_Visual_Analysis_of_Physiological_Event_Streams
3. https://www.researchgate.net/publication/311531916_CoRAD_Visual_Analytics_for_Cohort_Analysis
4. https://www.researchgate.net/publication/281662808_Collaborative_multi-touch_clinical_handover_system_for_the_neonatal_intensive_care_unit
5. https://www.researchgate.net/publication/263772728_A_Real-Time_Multi-Dimensional_Visualization_Framework_For_Critical_And_Complex_Environments