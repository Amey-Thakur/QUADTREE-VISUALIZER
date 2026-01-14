<div align="center">

  <a name="readme-top"></a>
  # QuadTree Visualizer

  [![License: MIT](https://img.shields.io/badge/License-MIT-lightgrey)](LICENSE)
  ![Status](https://img.shields.io/badge/Status-Completed-success)
  [![Frontend](https://img.shields.io/badge/Frontend-Next.js%20%7C%20React%20%7C%20TypeScript-blueviolet)](https://github.com/Amey-Thakur/QUADTREE-VISUALIZER)
  [![Research](https://img.shields.io/badge/Research-IJERT-orange)](https://ems.ijert.org/download-section_14TVPS67DSYEpSjrSUlGAmuer)
  [![Developed by Amey Thakur, Hasan Rizvi & Mega Satish](https://img.shields.io/badge/Developed%20by-Amey%20Thakur%2C%20Hasan%20Rizvi%20%26%20Mega%20Satish-blue)](https://github.com/Amey-Thakur/QUADTREE-VISUALIZER)

  A high-performance interactive simulation visualizing the efficiency of the QuadTree data structure in spatial partitioning and collision detection, built with Next.js and HTML5 Canvas.

  **[Source Code](Source%20Code/)** &nbsp;·&nbsp; **[Research Paper](Research%20Paper/IJERTV11IS040156%20-%20QuadTree%20Visualizer.pdf)** &nbsp;·&nbsp; **[Video Demo](https://youtu.be/8un0Qu8ibNk)** &nbsp;·&nbsp; **[Live Demo](https://amey-thakur.github.io/QUADTREE-VISUALIZER/)**

  [![QuadTree Visualizer Demo](https://img.youtube.com/vi/8un0Qu8ibNk/0.jpg)](https://youtu.be/8un0Qu8ibNk)

</div>

---

<div align="center">

  [Authors](#authors) &nbsp;·&nbsp; [Overview](#overview) &nbsp;·&nbsp; [Features](#features) &nbsp;·&nbsp; [Structure](#project-structure) &nbsp;·&nbsp; [Results](#results-gallery) &nbsp;·&nbsp; [Quick Start](#quick-start) &nbsp;·&nbsp; [Academic Record](#academic-documentation) &nbsp;·&nbsp; [Milestones](#educational-milestones) &nbsp;·&nbsp; [References](#literature-survey) &nbsp;·&nbsp; [Usage Guidelines](#usage-guidelines) &nbsp;·&nbsp; [License](#license) &nbsp;·&nbsp; [About](#about-this-repository) &nbsp;·&nbsp; [Acknowledgments](#acknowledgments)

</div>

---

<!-- AUTHORS -->
<a name="authors"></a>
<div align="center">

  ## Authors

  **Terna Engineering College | Computer Engineering | Batch of 2022**

| <a href="https://github.com/Amey-Thakur"><img src="https://github.com/Amey-Thakur.png" width="150" height="150" alt="Amey Thakur"></a><br>[**Amey Thakur**](https://github.com/Amey-Thakur)<br><br>[![ORCID](https://img.shields.io/badge/ORCID-0000--0001--5644--1575-green.svg)](https://orcid.org/0000-0001-5644-1575) | <a href="https://github.com/rizvihasan"><img src="https://github.com/rizvihasan.png" width="150" height="150" alt="Hasan Rizvi"></a><br>[**Hasan Rizvi**](https://github.com/rizvihasan)<br><br>[![GitHub](https://img.shields.io/badge/GitHub-rizvihasan-black?style=flat&logo=github)](https://github.com/rizvihasan) | <a href="https://github.com/msatmod"><img src="Mega/Mega.png" width="150" height="150" alt="Mega Satish"></a><br>[**Mega Satish**](https://github.com/msatmod)<br><br>[![ORCID](https://img.shields.io/badge/ORCID-0000--0002--1844--9557-green.svg)](https://orcid.org/0000-0002-1844-9557) |
| :---: | :---: | :---: |

  *Project Guide: **Prof. Randeep Kaur Kahlon** ([Area of Specialization](Major-Project%20Selection/Project%20Guide%20Area%20of%20specialization%202021%20-%202022.pdf))*

</div>

> [!IMPORTANT]
> ### 🤝🏻 Special Acknowledgement
> *Special thanks to **[Hasan Rizvi](https://github.com/rizvihasan)**, **[Mega Satish](https://github.com/msatmod)** and **Prof. Randeep Kaur Kahlon** for their meaningful contributions, guidance, and support that helped shape this work.*

---

<!-- OVERVIEW -->
<a name="overview"></a>
## Overview

**QuadTree Visualizer** is a comprehensive tool designed to demonstrate the efficacy of QuadTrees in optimizing spatial querying and collision detection. Unlike naive O(N²) collision checks, this system implements an efficient hierarchical data structure, visualizing `insert`, `retrieve`, and `clear` operations in real-time.

The application allows users to spawn varying numbers of particles, apply physics forces, and observe how the QuadTree dynamically partitions the 2D space to reduce computational complexity.

<div align="center">
  <img src="https://user-images.githubusercontent.com/54937357/165129412-cbc12312-2797-48a7-ad1f-c22253be4fa0.gif" alt="QuadTree" width="350" height="350">
  <img src="https://user-images.githubusercontent.com/54937357/165130570-bbab7825-fbbc-4b98-908e-1f591ac6d91e.gif" alt="QuadTree" width="350" height="350">
</div>

> [!NOTE]
> **Research Impact & Certification**
>
> This project was published as a research paper in the **International Journal of Engineering Research & Technology (IJERT)** (Volume 11, Issue 04) and is also available as a preprint on **viXra**. The project received an official **Publication Certificate** for its research contribution to engineering education.
>
> - [Preprint @viXra](https://vixra.org/abs/2204.0168)
> - [Published Paper @IJERT](https://ems.ijert.org/download-section_14TVPS67DSYEpSjrSUlGAmuer)
> - [Research Paper PDF](Research%20Paper/IJERTV11IS040156%20-%20QuadTree%20Visualizer.pdf)
> - [Publication Certificate](Research%20Paper/Certificates/IJERTV11IS040156%20Certificate%20-%20Amey%20Thakur.pdf)

### Engineering Thesis

| # | Name | Student ID | Thesis | Certificate | Description |
| :-: | :--- | :---: | :---: | :---: | :--- |
| 1 | **Amey Thakur** | TU3F1819127 | [View](BlackBook/BlackBook-Amey_Mahendra_Thakur-TU3F1819127.pdf) | [View](Research%20Paper/Certificates/IJERTV11IS040156%20Certificate%20-%20Amey%20Thakur.pdf) | Official Engineering Thesis |
| 2 | **Hasan Rizvi** | TU3F1819130 | [View](BlackBook/BlackBook-Hasan_Mehdi_Rizvi-TU3F1819130.pdf) | [View](Research%20Paper/Certificates/IJERTV11IS040156%20Certificate%20-%20Hasan%20Rizvi.pdf) | Official Engineering Thesis |
| 3 | **Mega Satish** | TU3F1819139 | [View](BlackBook/BlackBook-Mega_Satish_Modha-TU3F1819139.pdf) | [View](Research%20Paper/Certificates/IJERTV11IS040156%20Certificate%20-%20Mega%20Satish.pdf) | Official Engineering Thesis |
| 4 | **Ajay Davare** | TU3F1718006 | [View](BlackBook/BlackBook-Ajay_Ramesh_Davare-TU3F1718006.pdf) | [View](Research%20Paper/Certificates/IJERTV11IS040156%20Certificate%20-%20Ajay%20Davare.pdf) | Official Engineering Thesis |
| 5 | **Prof. Randeep Kaur Kahlon** | Guide | - | [View](Research%20Paper/Certificates/IJERTV11IS040156%20Certificate%20-%20Randeep%20Kaur%20Kahlon.pdf) | Project Guide & Mentor |
| 6 | **Group** | - | [View](BlackBook/BlackBook-Amey-TU3F1819127_Hasan-TU3F1819130_Mega-TU3F1819139_Ajay-TU3F1718006.pdf) | - | Combined Major Project Thesis |

<p align="center">
  <h3>Defense Day Photos (April 25, 2022 - Monday) [10:53 AM]</h3>
  <br>
  <img src="25-04-2022/2022-04-25%20at%2010.53.18.jpeg" width="100%" />
  <br>
  <img src="25-04-2022/2022-04-25%20at%2010.53.19.jpeg" width="100%" />
</p>

### Additional Resources

| Resource | Description |Z
|---|---|
| [**Plagiarism Report**](Research%20Paper/QuadTree_Visualizer_Plagiarism_Report.pdf) | Detailed analysis of content originality |
| [**Scan Report**](Research%20Paper/QuadTree_Visualizer_Plagiarism_Scan_Report.pdf) | Automated similarity index scan result |
| [**Acceptance Letter**](Research%20Paper/IJERTV11IS040156_Acceptance.pdf) | Official acceptance from IJERT Editorial Board |
| [**Payment Receipt**](Research%20Paper/IJERTV11IS040156_payment-receipt.pdf) | Processing fee transaction confirmation |

> [!TIP]
> **Performance Insight & Algorithm Visualization**
>
> This project empirically demonstrates the **O(N log N)** efficiency of QuadTree spatial partitioning compared to the traditional **O(N²)** brute-force approach for collision detection. The visualization serves as a practical, interactive tool for understanding how recursive subdivision optimizes computational load in dense particle systems.

---

<!-- FEATURES -->
<a name="features"></a>
## Features

| Feature | Description |
|---------|-------------|
| **Interactive Simulation** | Real-time particle system with adjustable spawn rates and physics. |
| **Dynamic Partitioning** | Visual representation of QuadTree nodes splitting and merging. |
| **Collision Detection** | Efficient O(N log N) collision checks visualized. |
| **Control Panel** | Tweak simulation parameters (capacity, boundary, speed) on the fly. |
| **Data Generation** | Modes for Random bodies, Spawned bodies, or mixed scenarios. |

### Tech Stack
- **Framework**: Next.js 14, React 18
- **Component Library**: Material UI (MUI v5)
- **Language**: TypeScript
- **Styling**: SCSS (Modules)
- **Graphics**: HTML5 Canvas API

---

<!-- STRUCTURE -->
<a name="project-structure"></a>
## Project Structure

```python
QUADTREE-VISUALIZER/
│
├── .github/                                                      # GitHub Workflows & Metadata
│   └── workflows/
│       └── deploy.yml                                            # CI/CD Deployment Workflow
│
├── 25-04-2022/                                                   # Historical Project Snapshot
│   ├── 2022-04-25 at 10.53.18.jpeg                               # Defense Day Photo 1
│   ├── 2022-04-25 at 10.53.19.jpeg                               # Defense Day Photo 2
│   ├── 2022-04-25_at_10.53.19_Transparent.png                    # Defense Day Photo (Transparent)
│   ├── Final Presentation.pdf                                    # Final Defense Presentation (PDF)
│   ├── Final Presentation.pptx                                   # Final Defense Presentation (PPTX)
│   ├── Gmail - Photos.pdf                                        # Email Correspondence
│   ├── Presentation_Preparation.pdf                              # Prep Notes (PDF)
│   └── Presentation_Preparation.txt                              # Prep Notes (TXT)
│
├── BlackBook/                                                    # Official Engineering Thesis Documents
│   ├── BlackBook Cover Pages/                                    # Thesis Cover Designs
│   ├── Certificates/                                             # Signed Completion Certificates
│   ├── Draft/                                                    # Thesis Draft Versions
│   ├── BlackBook-Ajay_Ramesh_Davare-TU3F1718006.pdf              # Individual Thesis (Ajay Davare)
│   ├── BlackBook-Amey_Mahendra_Thakur-TU3F1819127.pdf            # Individual Thesis (Amey Thakur)
│   ├── BlackBook-Hasan_Mehdi_Rizvi-TU3F1819130.pdf               # Individual Thesis (Hasan Rizvi)
│   ├── BlackBook-Mega_Satish_Modha-TU3F1819139.pdf               # Individual Thesis (Mega Satish)
│   └── BlackBook-Group-Combined.pdf                              # Combined Major Project Thesis
│
├── docs/                                                         # Formal Documentation
│   └── SPECIFICATION.md                                          # Technical Architecture & Spec
│
├── Initial Work/                                                 # Early Prototypes & Research
│   ├── Initial PPTs/                                             # Idea Pitch Decks
│   ├── Phi Education/                                            # Educational Context
│   ├── Phi Tasks/                                                # Task Assignments
│   ├── QuadTree Implementation Examples/                         # Reference Implementations
│   ├── Phi Portal Dashboard.png                                  # UI Mockup - Dashboard
│   ├── Phi Portal Login.png                                      # UI Mockup - Login
│   └── Phi Portal Project Plan.png                               # Project Roadmap Visual
│
├── Major-Project Selection/                                      # Topic Selection & Approval Records
│   ├── BE STUDENTS LIST SH21/                                    # Student Batch List
│   ├── Approval Message.png                                      # Guide Approval Proof
│   ├── B.E. Major Project Team Building Details_FH2021.pdf       # Team Formation Doc
│   ├── BE Major Project Details of Div A_B_C_AY21_22_ Final.xlsx # Division Details
│   ├── BE STUDENTS LIST SH21.zip                                 # Student List Archive
│   ├── EPIC TN04_Master_BTechProjectList_TitlesForSelection.xlsx # Title Selection List
│   ├── Final Year Project.jpg                                    # Project Concept Art
│   ├── PHI-CS-73.jpeg                                            # Group ID Badge
│   ├── Project Guide Area of specialization 2021 - 2022.pdf      # Guide Domain List
│   ├── Project Guide Area of specialization 2021 - 2022.xlsx     # Guide Domain Data
│   ├── Studentcopy_TN04_BE_SH2021_SEM VII_PROJECT REVIEW.xlsx    # Review Details
│   └── TN04_Project Guide Selection.pdf                          # Allocation Letter
│
├── Major-Project-I/                                              # Semester VII Project Phase
│   ├── MAJOR_PROJECT-I_REPORT_PHI-CS-73.pdf                      # Phase I Report
│   ├── MAJOR_PROJECT_BE-COMPS_B-50,51,58.docx                    # Draft Report
│   ├── Major Project Attendance [25-10-2021].jpeg                # Attendance Record
│   ├── QuadTree_Visualizer_Major-Project-I_CS-73.pdf             # Phase I Presentation (PDF)
│   ├── QuadTree_Visualizer_Major-Project-I_CS-73.pptx            # Phase I Presentation (PPTX)
│   ├── Review_Major-Project-I_Attendance_Proof.png               # Review Attendance
│   ├── Studentcopy_TN04_BE_SH2021 _SEM VII_PROJECT REVIEW.xlsx   # Grading Sheet
│   └── TN04_CS Project Details of Div A_B_C Final 27th Aug.xlsx  # Division Allocations
│
├── Major-Project-II/                                             # Semester VIII Project Phase
│   ├── MAJOR_PROJECT-II_REPORT_PHI-CS-73.docx                    # Phase II Report (Docx)
│   ├── MAJOR_PROJECT-II_REPORT_PHI-CS-73.pdf                     # Phase II Report (PDF)
│   ├── Major-Project Report.pdf                                  # Final Report Draft
│   ├── QuadTree_Visualizer_Major-Project-II_CS-73.pdf            # Phase II Presentation (PDF)
│   └── QuadTree_Visualizer_Major-Project-II_CS-73.pptx           # Phase II Presentation (PPTX)
│
├── Mega/                                                         # Archival Attribution Assets
│   ├── Filly.jpg                                                 # Companion (Filly)
│   └── Mega.png                                                  # Author Profile Image (Mega Satish)
│
├── Reference Papers/                                             # Literature Survey & Bibliography
│   ├── A Quadtree-based Hierarchical Clustering Method.pdf       # Reference Paper
│   ├── An Effective Way to Represent Quadtrees.pdf               # Reference Paper
│   ├── Efficient Quadtree Coding of Images and Video.pdf         # Reference Paper
│   ├── Energetics of a bouncing drop.pdf                         # Physics Reference
│   ├── Kinetic Compressed Quadtrees in the Black-Box Model.pdf   # Algorithm Reference
│   ├── Nodejs - Using JavaScript to Build...pdf                  # Tech Stack Reference
│   ├── Optimal Quadtree Construction Algorithms.pdf              # Algorithm Reference
│   └── Quad-Tree Motion Modelling with Leaf Merging.pdf          # Algorithm Reference
│
├── Research Paper/                                               # Published Research Assets
│   ├── Certificates/                                             # Publication Certificates (IJERT)
│   ├── Draft/                                                    # Paper Drafts
│   ├── IJERT/                                                    # Journal Correspondence
│   ├── IJERTV11IS040156 - QuadTree Visualizer.pdf                # Published Paper
│   ├── IJERTV11IS040156_Acceptance.pdf                           # Acceptance Letter
│   ├── IJERTV11IS040156_payment-receipt.pdf                      # Payment Receipt
│   ├── QuadTree_Visualizer_Plagiarism_Report.pdf                 # Plagiarism Report
│   └── QuadTree_Visualizer_Plagiarism_Scan_Report.pdf            # Scan Report
│
├── Review-1/                                                     # First Progress Review
│   ├── QuadTree_Visualizer_Review-1_CS-73.pdf                    # Review 1 Report
│   ├── QuadTree_Visualizer_Review-1_CS-73.pptx                   # Review 1 Presentation
│   ├── Review-1_Attendance_Proof.png                             # Attendance Proof
│   └── Review-1_Panel.jpg                                        # Panel Photo
│
├── Review-2/                                                     # Second Progress Review
│   ├── QuadTree_Visualizer_Review-2_CS-73.pdf                    # Review 2 Report
│   └── QuadTree_Visualizer_Review-2_CS-73.pptx                   # Review 2 Presentation
│
├── Review-3/                                                     # Third Progress Review
│   ├── BE Major Project Review3 Student Schedule FH22.xlsx       # Schedule Data
│   ├── QuadTree_Visualizer_Review-3_CS-73.pdf                    # Review 3 Report
│   ├── QuadTree_Visualizer_Review-3_CS-73.pptx                   # Review 3 Presentation
│   ├── Review-3_Panel.png                                        # Panel Photo
│   └── Review-3_Schedule.png                                     # Schedule Image
│
├── Review-4/                                                     # Final Defense Review
│   ├── QuadTree_Visualizer_Review-4_CS-73.pdf                    # Final Review Report
│   └── QuadTree_Visualizer_Review-4_CS-73.pptx                   # Final Review Presentation
│
├── Source Code/                                                  # Application Source
│   └── quadtree-visualizer/                                      # Next.js Application Root
│       ├── components/                                           # React UI Components
│       ├── pages/                                                # App Routes
│       ├── public/                                               # Static Assets
│       ├── styles/                                               # SCSS Theme Files
│       ├── utils/                                                # Core QuadTree Logic & Physics Engine
│       └── package.json                                          # Dependencies
│
├── Source Code Output/                                           # Result Artifacts
│   └── Outputs.pdf                                               # Complete Output Gallery
│
├── Submission Report/                                            # Final Submission Docs
│   ├── Amey_B-50_Submission_Report.pdf                           # Submission Receipt (Amey)
│   ├── Hasan_B-51_Submission_Report.pdf                          # Submission Receipt (Hasan)
│   └── Mega_B-58_Submission_Report.pdf                           # Submission Receipt (Mega)
│
├── .gitattributes                                                # Git configuration
│
├── .gitignore                                                    # Git exclusion rules
├── BE-Major-Project.jpeg                                         # Project Banner Image
├── CITATION.cff                                                  # Scholarly Citation Metadata
├── codemeta.json                                                 # Machine-Readable Project Metadata
├── LICENSE                                                       # MIT License Terms
├── README.md                                                     # Comprehensive Archival Entrance
└── SECURITY.md                                                   # Vulnerability Exposure Policy
```

---

<!-- RESULTS -->
<a name="results-gallery"></a>
## Results Gallery

<div align="center">

![Homepage](Source%20Code%20Output/Homepage.png)

![Control Panel](Source%20Code%20Output/Control%20Panel.png)

![Spawn Bodies](Source%20Code%20Output/Spawn%20Bodies.png)

![Random Bodies](Source%20Code%20Output/Random%20%26%20Spawn%20Bodies.png)

![Clear QuadTree](Source%20Code%20Output/Clear%20QuadTree.png)

</div>

---

## QuadTree Generation from Images

<div align="center">

An experimental implementation generating QuadTrees from static images.

**[Kaggle Notebook](https://www.kaggle.com/code/ameythakur20/quadtree)** &nbsp; | &nbsp; **[Kaggle Dataset](https://www.kaggle.com/datasets/ameythakur20/images)**

<img src="https://user-images.githubusercontent.com/54937357/134290440-0e70c3a3-4b3d-4dd6-8ac0-649c2d72e103.gif" alt="Image QuadTree" height="400">

</div>

### Additional Resources

| # | Resource | Type |
| :-: | :--- | :--- |
| 1 | [**QuadTree Notebook 1**](Initial%20Work/QuadTree%20Implementation%20Examples/QuadTree%20from%20Images/QuadTree_1.ipynb) | Jupyter Notebook |
| 2 | [**QuadTree Notebook 2**](Initial%20Work/QuadTree%20Implementation%20Examples/QuadTree%20from%20Images/QuadTree_2.ipynb) | Jupyter Notebook |
| 3 | [**Kaggle Notebook**](https://www.kaggle.com/code/ameythakur20/quadtree) | External Link |
| 4 | [**Kaggle Dataset**](https://www.kaggle.com/datasets/ameythakur20/images) | External Link |
| 5 | [**Croatia**](Initial%20Work/QuadTree%20Implementation%20Examples/QuadTree%20from%20Images/IMAGES/Croatia.jpg) | Image |
| 6 | [**Filly (Version 2)**](Initial%20Work/QuadTree%20Implementation%20Examples/QuadTree%20from%20Images/IMAGES/Filly-2.jpg) | Image |
| 7 | [**Filly (InstaDP)**](Initial%20Work/QuadTree%20Implementation%20Examples/QuadTree%20from%20Images/IMAGES/Filly-InstaDP.jpg) | Image |
| 8 | [**Filly**](Initial%20Work/QuadTree%20Implementation%20Examples/QuadTree%20from%20Images/IMAGES/Filly.jpg) | Image |
| 9 | [**Gateway of India**](Initial%20Work/QuadTree%20Implementation%20Examples/QuadTree%20from%20Images/IMAGES/Gateway%20of%20India.jpg) | Image |
| 10 | [**Injila**](Initial%20Work/QuadTree%20Implementation%20Examples/QuadTree%20from%20Images/IMAGES/Injila.jpg) | Image |
| 11 | [**Lake**](Initial%20Work/QuadTree%20Implementation%20Examples/QuadTree%20from%20Images/IMAGES/Lake.jpg) | Image |
| 12 | [**Park**](Initial%20Work/QuadTree%20Implementation%20Examples/QuadTree%20from%20Images/IMAGES/park.jpg) | Image |

---

<!-- QUICK START -->
<a name="quick-start"></a>
## Quick Start

### 1. Prerequisites
Ensure your environment meets the minimum specifications:
- **Node.js**: Version **14** or higher.
- **npm**: Version **6** or higher.
- **Browser**: Modern web browser (Chrome/Edge recommended) for HTML5 Canvas.

> [!WARNING]
> **Technical Dependencies & Environment**
>
> This system relies on **HTML5 Canvas** for high-performance graphical rendering and **Node.js** for the development server. For stable execution and accurate visual output, ensure that dependencies are installed cleanly and the application is run in a standard modern browser environment.

### 2. Setup & Deployment
1.  **Clone the Repository**:
    ```bash
    git clone https://github.com/Amey-Thakur/QUADTREE-VISUALIZER.git
    cd QUADTREE-VISUALIZER
    ```
2.  **Install Dependencies**:
    Navigate to the source directory and install the required packages:
    ```bash
    cd "Source Code/quadtree-visualizer/"
    npm install
    ```

### 3. Launch Application
1.  **Start the Development Server**:
    ```bash
    npm run dev
    ```
2.  **Access Web Gateway**:
    -   Navigate to: `http://localhost:3000`

---

<!-- ACADEMIC DOCUMENTATION -->
## Academic Documentation

This section archives the formal evaluation milestones and scholarly projects associated with the Bachelor of Engineering (B.E.) degree in Computer Engineering.


### 1. Academic Evaluation Manifest

A chronological record of technical reviews, phase reports, and formal evaluations conducted by the institutional review board.

| Milestone | Timeline | Evaluation Focal Point | Official Documentation | Evidence |
| :--- | :---: | :--- | :---: | :---: |
| **Project Inception** | 2021 | Research Domain Selection & Supervisory Allocation | [Selection Document](Major-Project%20Selection/B.E.%20Major%20Project%20Team%20Building%20Details_FH2021.pdf) | [Approval](Major-Project%20Selection/Approval%20Message.png) |
| **Review 1** | Second Half 2021 | 2:48 PM \| Formative Assessment Stage I (Review Board) | [PPTX](Review-1/QuadTree_Visualizer_Review-1_CS-73.pptx) \| [PDF](Review-1/QuadTree_Visualizer_Review-1_CS-73.pdf) | [Panel](Review-1/Review-1_Panel.jpg) \| [Attendance](Review-1/Review-1_Attendance_Proof.png) |
| **Review 2** | Second Half 2021 | Progress Review & Interim Technical Presentation | [PPTX](Review-2/QuadTree_Visualizer_Review-2_CS-73.pptx) \| [PDF](Review-2/QuadTree_Visualizer_Review-2_CS-73.pdf) | - |
| **Major Project - I** | October 25, 2021 | 12:29 PM \| Summative Evaluation Phase I (`Meet: vqt-diqt-edq`) | [Report](Major-Project-I/QuadTree_Visualizer_Major-Project-I_CS-73.pdf) \| [Docx](Major-Project-I/MAJOR_PROJECT_BE-COMPS_B-50,51,58.docx) | [Attendance](Major-Project-I/Major%20Project%20Attendance%20%5B25-10-2021%5D.jpeg) |
| **Review 3** | First Half 2022 | Critical Path Scheduling & Methodological Validation | [PPTX](Review-3/QuadTree_Visualizer_Review-3_CS-73.pptx) \| [PDF](Review-3/QuadTree_Visualizer_Review-3_CS-73.pdf) | [Schedule](Review-3/Review-3_Schedule.png) \| [Panel](Review-3/Review-3_Panel.png) |
| **Review 4** | First Half 2022 | Formative Assessment Stage II (Architectural Synthesis) | [PPTX](Review-4/QuadTree_Visualizer_Review-4_CS-73.pptx) \| [PDF](Review-4/QuadTree_Visualizer_Review-4_CS-73.pdf) | - |
| **Major Project - II** | First Half 2022 | Summative Evaluation Phase II (Final Technical Repository) | [Final Report](Major-Project-II/QuadTree_Visualizer_Major-Project-II_CS-73.pdf) \| [Docx](Major-Project-II/MAJOR_PROJECT-II_REPORT_PHI-CS-73.docx) | - |
| **Final Defense** | April 25, 2022 | 10:53 AM \| Final Scholarly Defense & Viva Voce | [Presentation](25-04-2022/Final%20Presentation.pdf) \| [Preparation](25-04-2022/Presentation_Preparation.pdf) | [Photos](#defense-day-photos-april-25-2022---monday-1053-am) |

### Research & Evaluation Evidence

<div align="center">
  <h4>Research Domain Selection & Institutional Approval</h4>
  <img src="Major-Project%20Selection/Approval%20Message.png" width="50%" />
</div>

<div align="center">
  <h4>Formative Assessment Stage I (Institutional Review Board)</h4>
  <img src="Review-1/Review-1_Panel.jpg" width="85%" />
</div>

<div align="center">
  <h4>Institutional Attendance Record (Second Half 2021)</h4>
  <img src="Review-1/Review-1_Attendance_Proof.png" width="85%" />
</div>

<div align="center">
  <h4>Summative Evaluation Phase I (Institutional Attendance Audit)</h4>
  <img src="Major-Project-I/Major%20Project%20Attendance%20%5B25-10-2021%5D.jpeg" width="85%" />
</div>

<div align="center">
  <h4>Critical Path Scheduling & Methodological Validation</h4>
  <img src="Review-3/Review-3_Schedule.png" width="85%" />
</div>

<div align="center">
  <h4>Formative Assessment Stage II (Architectural Synthesis Panel)</h4>
  <img src="Review-3/Review-3_Panel.png" width="85%" />
</div>

<div align="center">
  <h3 id="defense-day-photos-april-25-2022---monday-1053-am">Final Scholarly Defense & Viva Voce (April 25, 2022 - Monday) [10:53 AM]</h3>
  <br>
  <img src="25-04-2022/2022-04-25%20at%2010.53.18.jpeg" width="45%" />
  &nbsp;
  <img src="25-04-2022/2022-04-25%20at%2010.53.19.jpeg" width="45%" />
</div>

### 2. Scholarly Publication & Technical Integrity

Formal research contribution published in the **International Journal of Engineering Research & Technology (IJERT)**, including authenticity audits.

| Scholarly Project | Institutional Record | Integrity Manifest | Technical Submission |
| :--- | :--- | :--- | :---: |
| **Technical Paper** | IJERT Vol 11, Issue 04 | [Plagiarism Report](Research%20Paper/QuadTree_Visualizer_Plagiarism_Report.pdf) | [Final Paper](Research%20Paper/IJERTV11IS040156%20-%20QuadTree%20Visualizer.pdf) |
| **Official Acceptance** | Editorial Board Approval | [Acceptance Letter](Research%20Paper/IJERTV11IS040156_Acceptance.pdf) | [Preprint](https://vixra.org/abs/2204.0168) |
| **Publication Merit** | Publication Certificate | [Payment Receipt](Research%20Paper/IJERTV11IS040156_payment-receipt.pdf) | [View](Research%20Paper/Certificates/IJERTV11IS040156%20Certificate%20-%20Amey%20Thakur.pdf) |

### 3. Official Engineering Thesis Archival (Black Book)

Archival records of the comprehensive engineering thesis submitted to the **University of Mumbai**.

| # | Contributor | Institutional ID | Document Scope | Archival Record |
| :-: | :--- | :---: | :--- | :---: |
| 1 | **Amey Thakur** | TU3F1819127 | Individual Engineering Thesis | [View PDF](BlackBook/BlackBook-Amey_Mahendra_Thakur-TU3F1819127.pdf) |
| 2 | **Hasan Rizvi** | TU3F1819130 | Individual Engineering Thesis | [View PDF](BlackBook/BlackBook-Hasan_Mehdi_Rizvi-TU3F1819130.pdf) |
| 3 | **Mega Satish** | TU3F1819139 | Individual Engineering Thesis | [View PDF](BlackBook/BlackBook-Mega_Satish_Modha-TU3F1819139.pdf) |
| 4 | **Ajay Davare** | TU3F1718006 | Individual Engineering Thesis | [View PDF](BlackBook/BlackBook-Ajay_Ramesh_Davare-TU3F1718006.pdf) |
| 5 | **Team compilation** | CSP705 / CSP805 | Combined Major Project Thesis | [View PDF](BlackBook/BlackBook-Amey-TU3F1819127_Hasan-TU3F1819130_Mega-TU3F1819139_Ajay-TU3F1718006.pdf) |
| 6 | **Submission Receipt** | - | Official Submission Evidence | [Amey](Submission%20Report/Amey_B-50_Submission_Report.pdf) \| [Hasan](Submission%20Report/Hasan_B-51_Submission_Report.pdf) \| [Mega](Submission%20Report/Mega_B-58_Submission_Report.pdf) |

---

<!-- PEDAGOGICAL FOUNDATION -->
<a name="educational-milestones"></a>
## Pedagogical Foundation & Technical Proficiency Manifest

**Institutional Mentor**: Phi Education | **Project Team**: [Amey Thakur](https://github.com/Amey-Thakur), [Mega Satish](https://github.com/msatmod), [Hasan Rizvi](https://github.com/rizvihasan)

This section archives the foundational technical training and pedagogical milestones completed under the **Phi Education** track. These assessments document the chronological progression of technical proficiency in C-based systems programming and structural optimization, serving as the technical foundation for the project's final implementation.

### 1. Foundational Technical Assessment & Training Matrix

| Objective | Timeline | Scholarly Project & Training Module | Technical Assessment | Inquiry & Resolution | Approved Outcome |
| :--- | :---: | :--- | :---: | :---: | :---: |
| **Logic & Paradigm** | September 17, 2021 | [Object-Oriented Paradigm Simulation in C](Initial%20Work/Phi%20Tasks/Task%201) | [Assessment](Initial%20Work/Phi%20Tasks/Task%201/Task%2001.png) | - | [Approved](Initial%20Work/Phi%20Tasks/Task%201/PHI%20CS%2073%20-%20Task%201%20%5BSUBMISSION%20-%203%5D%20APPROVED.png) |
| **Design Synthesis** | October 01, 2021 | [Structural Design Patterns & Logic Validation](Initial%20Work/Phi%20Tasks/Task%202) | [Assessment](Initial%20Work/Phi%20Tasks/Task%202/Task%2002.png) | [Inquiry](Initial%20Work/Phi%20Tasks/Task%202/Doubts.pdf) | [Approved](Initial%20Work/Phi%20Tasks/Task%202/PHI%20CS%2073%20-%20Task%202%20%5BSUBMISSION%20-%2015%5D%20APPROVED.png) |
| **XML Processing** | - | [Hierarchical Data Extraction via TinyXml](Initial%20Work/Phi%20Tasks/Task%203) | [Assessment](Initial%20Work/Phi%20Tasks/Task%203/Task%2003.png) | [Inquiry](Initial%20Work/Phi%20Tasks/Task%203/Doubts.png) | [Approved](Initial%20Work/Phi%20Tasks/Task%203/PHI-CS-73%20TASK-3%20%5BSUBMISSION-1%5D%20APPROVED.png) |
| **Spatial Logic** | - | [Formal ADT Specification for Spatial Partitioning](Initial%20Work/Phi%20Tasks/Task%204) | [Assessment](Initial%20Work/Phi%20Tasks/Tasks%20Descriptions/Task4.jpeg) | [Inquiry](Initial%20Work/Phi%20Tasks/Task%204/Doubts.png) \| [Resolution](Initial%20Work/Phi%20Tasks/Task%204/Doubts-Response.png) | - |
| **Data Definition** | - | [Formal Specification of Persistence File Formats](Initial%20Work/Phi%20Tasks/Tasks%20Descriptions/Task5.jpeg) | - | - | [Pending] |
| **Interface Design** | - | [Architectural Synthesis of the `pcf_ui` Library](Initial%20Work/Phi%20Tasks/Task%206) | - | - | [Repository](Initial%20Work/Phi%20Tasks/Task%206) |
| **Advanced Logic** | - | [Cumulative Theoretical Logic & System Modeling](Initial%20Work/Phi%20Tasks/Tasks%20Descriptions/) | - | - | [Modules 07-10] |
| **Thesis Prep** | April 2022 | [Foundational Technical Thesis Presentation](Initial%20Work/Initial%20PPTs/QUADTREE%20VISUALIZER.pdf) | [PDF](Initial%20Work/Initial%20PPTs/MAJOR_PROJECT-I_FINAL_REVIEW_PHI-CS-73.pdf) | [PPTX](Initial%20Work/Initial%20PPTs/QUADTREE%20VISUALIZER.pptx) | [PDF](Initial%20Work/Initial%20PPTs/QUADTREE%20VISUALIZER.pdf) |

### 2. Foundational Programming Curriculum (C-Systems)

A record of fundamental C-Programming milestones archiving the pedagogical seeds of the project's core spatial algorithms.

| Milestone | Knowledge Module | Technical Focus & System Artifacts | Evaluation |
| :---: | :--- | :--- | :---: |
| **01** | [Geometry & Logic](Initial%20Work/Phi%20Education/Introduction%20To%20C%20Programming/Milestone_1) | Basic Geometry & Unit Conversions (`Area Calculation Engine`) | [View](Initial%20Work/Phi%20Education/Milestone%201%20Completed.png) |
| **02** | [Algorithmic Finance](Initial%20Work/Phi%20Education/Introduction%20To%20C%20Programming/Milestone_2) | Mathematical Logic & Finance ADTs (`GCD`, `LCM`, `Compound Interest`) | [View](Initial%20Work/Phi%20Education/Milestone%202%20Completed.png) |
| **03** | [Linear Data Structures](Initial%20Work/Phi%20Education/Introduction%20To%20C%20Programming/Milestone_3) | Fundamental Array Operations (`Search`, `Sort` Implementations) | [View](Initial%20Work/Phi%20Education/Milestone%203%20Completed.png) |
| **04** | [Array Optimization](Initial%20Work/Phi%20Education/Introduction%20To%20C%20Programming/Milestone_4) | Advanced Spatial Array Manipulations (`ARRAYOP.C`) | [View](Initial%20Work/Phi%20Education/Milestone%204%20Completed.png) |
| **05** | [Lexical Processing I](Initial%20Work/Phi%20Education/Introduction%20To%20C%20Programming/Milestone_5) | String Library Implementation (`strcompare`, `strfindsubstring`) | [View](Initial%20Work/Phi%20Education/Milestone%205%20Completed.png) |
| **06** | [Lexical Processing II](Initial%20Work/Phi%20Education/Introduction%20To%20C%20Programming/Milestone_6) | Consolidated String Utility Engine (`STR.C`) | [View](Initial%20Work/Phi%20Education/Milestone%206%20Completed.png) |
| **07** | [Analytical Algorithms](Initial%20Work/Phi%20Education/Introduction%20To%20C%20Programming/Milestone_7) | Complex String Analysis Algorithms (`stringoperation.C`) | [View](Initial%20Work/Phi%20Education/Milestone%207%20Completed.png) |
| **08** | [Polymorphic Logic](Initial%20Work/Phi%20Education/Introduction%20To%20C%20Programming/Milestone_8) | Polymorphic Sorting Concepts (`sortdatatype.C`) | [View](Initial%20Work/Phi%20Education/Milestone%208%20Completed.png) |
| **09** | [Dynamic Memory](Initial%20Work/Phi%20Education/Introduction%20To%20C%20Programming/Milestone_9) | Linked List Data Structures (`Recursive Reverse`, `Merge Sort`) | [View](Initial%20Work/Phi%20Education/Milestone%209%20Completed.png) |
| **10** | [Dictionary ADT](Initial%20Work/Phi%20Education/Introduction%20To%20C%20Programming/Milestone_10) | Dictionary ADT Implementation via Hashing Logic | [View](Initial%20Work/Phi%20Education/Milestone%2010%20Completed.png) |
| **11** | [File I/O Systems](Initial%20Work/Phi%20Education/Introduction%20To%20C%20Programming/Milestone_11) | Sequential File Processing & Tokenization (`FILEREAD.C`) | [View](Initial%20Work/Phi%20Education/Milestone%2011%20Completed.png) |
| **12** | [Persistence Models](Initial%20Work/Phi%20Education/Introduction%20To%20C%20Programming/Milestone_12) | Persistent Data Storage Mechanisms (`arrayfile.C`, `dictionary.C`) | [View](Initial%20Work/Phi%20Education/Milestone%2012%20Completed.png) |
| **13** | [Recursive Logic](Initial%20Work/Phi%20Education/Introduction%20To%20C%20Programming/Milestone_13) | Iterative & Recursive Data Structure Reversal | [View](Initial%20Work/Phi%20Education/Milestone%2013%20Completed.png) |
| **14** | [Optimization Metrics](Initial%20Work/Phi%20Education/Introduction%20To%20C%20Programming/Milestone_14) | Complex List Merging & Optimization Assessment (`14.c`) | [View](Initial%20Work/Phi%20Education/Milestone%2014%20Completed.png) |

### Technical Prototypes & Early Research Implementations

Before the final Next.js implementation, several iterative prototypes were developed to evaluate various spatial partitioning logic and collision detection algorithms. These artifacts represent the technical evolution of the project.

| <div align="center">Phase</div> | <div align="center">Research Artifact</div> | <div align="center">Technical Objective & Focus</div> |
| :---: | :--- | :--- |
| **P-01** | [QuadTree Collision Visualizer](Initial%20Work/QuadTree%20Implementation%20Examples/QuadTree%20Collision%20Visualizer) | Initial feasibility study comparing O(N²) vs O(N log N) spatial logic. |
| **P-02** | [QuadTree Library](Initial%20Work/QuadTree%20Implementation%20Examples/QuadTree%20Library) | Decoupling of the QuadTree engine into a reusable, modular C-based library. |
| **P-03** | [QuadTree Visualizer (Prototype)](Initial%20Work/QuadTree%20Implementation%20Examples/QuadTree%20Visualizer) | Early-stage integration of graphical visualization with the recursive partitioning engine. |

---

<!-- REFERENCES -->
<a name="literature-survey"></a>
## Literature Survey & Bibliography

The development of the **QuadTree Visualizer** was informed by a comprehensive review of established research in computational geometry, spatial data structures, and high-performance rendering. The following bibliography constitutes the primary theoretical foundation for this project:

1. **A Quadtree-based Hierarchical Clustering Method** | [View PDF](Reference%20Papers/A%20Quadtree-based%20Hierarchical%20Clustering%20Method%20for%20Visualizing%20Large%20Point%20Dataset.pdf)  
   *Focus: Optimization of large-scale spatial datasets.*
2. **An Effective Way to Represent Quadtrees** | [View PDF](Reference%20Papers/An%20Effective%20Way%20to%20Represent%20Quadtrees.pdf)  
   *Focus: Theoretical memory and structure efficiency.*
3. **Efficient Quadtree Coding of Images and Video** | [View PDF](Reference%20Papers/Efficient%20Quadtree%20Coding%20of%20Images%20and%20Video.pdf)  
   *Focus: Application of QuadTrees in signal processing.*
4. **Energetics of a Bouncing Drop** | [View PDF](Reference%20Papers/Energetics%20of%20a%20bouncing%20drop-Coefficient%20of%20restitution%2C%20bubble%20entrapment%2C%20and%20escape.pdf)  
   *Focus: Physics modeling and collision energetics.*
5. **Kinetic Compressed Quadtrees in the Black-Box Model** | [View PDF](Reference%20Papers/Kinetic%20Compressed%20Quadtrees%20in%20the%20Black-Box%20Model%20with%20Applications%20to%20Collision%20Detection%20for%20Low-Density%20Scenes.pdf)  
   *Focus: Advanced collision detection for dynamic systems.*
6. **Nodejs - High-Performance Network Programs** | [View PDF](Reference%20Papers/Nodejs%20-%20Using%20JavaScript%20to%20Build%20High-Performance%20Network%20Programs.pdf)  
   *Focus: Environment performance and real-time execution.*
7. **Optimal Quadtree Construction Algorithms** | [View PDF](Reference%20Papers/Optimal%20Quadtree%20Construction%20Algorithms.pdf)  
   *Focus: Recursive algorithm optimization.*
8. **Quad-Tree Motion Modelling with Leaf Merging** | [View PDF](Reference%20Papers/Quad-Tree%20Motion%20Modelling%20with%20Leaf%20Merging.pdf)  
   *Focus: Dynamic node management and leaf consolidation.*

---

<!-- =========================================================================================
                                     USAGE SECTION
     ========================================================================================= -->
<a name="usage-guidelines"></a>
## Usage Guidelines

This repository is openly shared to support learning and knowledge exchange across the academic community.

**For Students**  
Use this major project as a reference for understanding spatial partitioning, QuadTree data structures, and the implementation of recursive subdivision algorithms. The research assets and production scripts are documented to support self-paced learning and exploration of computational geometry.

**For Educators**  
This project may serve as a practical example or supplementary teaching resource for Computer Engineering curriculum or Major Project modules (`CSP705` and `CSP805`). Attribution is appreciated when utilizing content.

**For Researchers**  
The published paper and preprint provide insights into spatial partitioning logic, high-performance recursive algorithms, and the reduction of computational complexity in dynamic spatial environments.

---

<!-- LICENSE -->
<a name="license"></a>
## License

This repository and all linked academic content are made available under the **MIT License**. See the [LICENSE](LICENSE) file for complete terms.

> [!NOTE]
> **Summary**: You are free to share and adapt this content for any purpose, even commercially, as long as you provide appropriate attribution to the original author.

Copyright © 2022 Amey Thakur, Hasan Rizvi, Mega Satish

---

<!-- ABOUT -->
<a name="about-this-repository"></a>
## About This Repository

**Created & Maintained by**: [Amey Thakur](https://github.com/Amey-Thakur), [Mega Satish](https://github.com/msatmod) & [Hasan Rizvi](https://github.com/rizvihasan)  
**Academic Journey**: Bachelor of Engineering in Computer Engineering (2018-2022)  
**Institution**: [Terna Engineering College](https://ternaengg.ac.in/), Navi Mumbai  
**University**: [University of Mumbai](https://mu.ac.in/)

This repository serves as a permanent technical record for **QuadTree Visualizer**, developed as the **8th Semester Major Project**. It highlights the practical application of hierarchical data structures in spatial algorithm optimization and the deployment of high-performance interactive simulations via modern web interfaces.

**Connect**: [GitHub](https://github.com/Amey-Thakur) · [LinkedIn](https://www.linkedin.com/in/amey-thakur) · [ORCID](https://orcid.org/0000-0001-5644-1575)

### Acknowledgments
<a name="acknowledgments"></a>

Grateful acknowledgment to **[Mega Satish](https://github.com/msatmod)** and **[Hasan Rizvi](https://github.com/rizvihasan)** for their pivotal roles and collaborative excellence during the development of this project. Their intellectual contributions, technical insights, and dedicated commitment to software quality were fundamental in achieving the system's analytical and functional objectives. This technical record serves as a testament to their scholarly partnership and significant impact on the final implementation.

Special thanks to **Prof. Randeep Kaur Kahlon** for her mentorship and guidance as the project mentor throughout the research and development phases of this engineering thesis.

---

<div align="center">

  [↑ Back to Top](#readme-top)

  [Authors](#authors) &nbsp;·&nbsp; [Overview](#overview) &nbsp;·&nbsp; [Features](#features) &nbsp;·&nbsp; [Structure](#project-structure) &nbsp;·&nbsp; [Results](#results-gallery) &nbsp;·&nbsp; [Quick Start](#quick-start) &nbsp;·&nbsp; [Academic Record](#academic-documentation) &nbsp;·&nbsp; [Milestones](#educational-milestones) &nbsp;·&nbsp; [References](#literature-survey) &nbsp;·&nbsp; [Usage Guidelines](#usage-guidelines) &nbsp;·&nbsp; [License](#license) &nbsp;·&nbsp; [About](#about-this-repository) &nbsp;·&nbsp; [Acknowledgments](#acknowledgments)

  <br>

  🎬 **[QuadTree Visualizer](https://github.com/Amey-Thakur/QUADTREE-VISUALIZER)**

  ---

  ### Presented as part of the 8th Semester Major-Project @ Terna Engineering College

  ### 🎓 [Computer Engineering Repository](https://github.com/Amey-Thakur/COMPUTER-ENGINEERING)

  **Computer Engineering (B.E.) - University of Mumbai**

  *Semester-wise curriculum, laboratories, projects, and academic notes.*

</div>
