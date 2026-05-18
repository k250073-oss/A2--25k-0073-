# A2--25k-0073-
OOP Assignment 2
# FASTWheels Car Marketplace System (PakWheels Replication)
**Student ID:** 25k0073/ BAI-2A  
**Course:** Object-Oriented Programming (CS1004)  
**Instructor:** Talha Shahid  

---

## 1. Inheritance Relationships
We have implemented 7 distinct classes establishing 6 robust inheritance hierarchies to eliminate code duplication across the system:
* **User Branch:** `Buyer`, `Seller`, and `Admin` cleanly inherit from the abstract base `User` class to share primary identity configurations (ID, Name, Email, Phone).
* **Vehicle Branch:** `Car`, `Bike`, and `Truck` cleanly inherit from the abstract base `Vehicle` class to model shared physical domain tracking specs.
* **Message Branch:** `DirectMessage` inherits from `AbstractMessage` to support localized structural variations in live customer chat systems.

## 2. Polymorphic Features
* **Dynamic Binding (Method Overriding):** The pure virtual functions `displayProfile()` and `displayDetails()` are uniquely overridden within each target derived class frame. This allows universal pointers to dynamically switch behavior at runtime depending on the referenced object.
* **Static Binding (Method Overloading):** The `Marketplace` class implements overloaded variations of `searchListingsByBrand()`. This gives users the option to query matching records using either simple raw keyword targets or fine-grained maximum pricing constraints.

## 3. Abstraction & Interface Isolation
To meet core structural isolation requirements, 4 primary pure abstract configurations were completely isolated inside standalone interface header layers:
1. `Taxable.h` (Pure structural platform financial processing engine interface)
2. `User.h` (Abstract framework governing user profile architectures)
3. `Vehicle.h` (Abstract definition template governing physical asset classes)
4. `AbstractMessage.h` (Abstract architecture processing communication models)

## 4. Custom Operator Overloading
Four custom operators were overloaded to natively handle domain operations without utilizing standard procedural function blocks:
* `operator+` on `Marketplace`: Integrates clean expression syntaxes (`pakWheels + ad1;`) to cleanly register active advertisement listings into core arrays.
* `operator<` on `Listing`: Evaluates logical financial boundaries, natively resolving which model carries lesser financial metrics for automated marketplace catalog sorting.
* `operator==` on `Vehicle`: Natively audits structural equivalence across disparate vehicle instances (Brand, Model, and Year matching).
* `operator<<` on `Listing`: Enables direct stream insertion so standard system lines (`cout << ad1;`) dump readable data layouts instantly.

## 5. Secure Friend Interface Access
Four friend declarations were cleanly embedded within structural borders to allow secure access mapping over hidden private variables without introducing open getter mutations:
* `friend ostream& operator<<`: Facilitates direct private data dumps to console pipelines.
* `friend bool checkBuyerBudget`: Grants the `Buyer` security mechanism the right to securely evaluate localized cash bounds against a target listing asset's pricing field.
* `friend void verifyVehicleInspection`: Empowers an `Admin` identity token to access and update a `Vehicle` class item's private baseline inspection scores directly.

---

## 6. PakWheels Domain Feature Mapping, Code Sync & Engineering Justifications

This section directly maps live feature architectures from the PakWheels web platform onto the core object-oriented structures implemented across our modular C++ system framework.

---

### Feature A: Polymorphic Vehicle Ad Cataloging
**Website Context:** 
PakWheels functions as a versatile multi-category automobile repository. A standard user can browse distinct parameters for various vehicle form-factors—such as structural passenger sedans, lightweight consumer bikes, or heavy commercial haulers—all under a single centralized marketplace search stream.


**Live Website Interface Reference:**

<img width="710" height="492" alt="image" src="https://github.com/user-attachments/assets/ff8bbe85-8df5-4693-9c22-d50504c15f71" />
<img width="637" height="824" alt="image" src="https://github.com/user-attachments/assets/0622b715-f192-4d39-bb08-db0fdb97b8fc" />


**Replicated C++ Infrastructure Snippet:**


<img width="780" height="805" alt="image" src="https://github.com/user-attachments/assets/6ec958fb-d609-4e05-a8d6-767f433fdca1" />


**Architectural Reasoning & Justification:**
The live website demands highly varied attribute handling depending on asset classifications (e.g., tracking a bike's starter style vs a car's transmission type). We address this by applying Runtime Polymorphism. By abstracting common fields into a base Vehicle pattern and executing pure virtual displayDetails() hooks, the system allows heterogeneous arrays to process individual specialized formatting pipelines cleanly without exposing downcasting vulnerabilities.



### Feature B: Role Partitioning & User Profiling
**Website Context:** The portal separates specific behavioral models depending on member classifications. A basic private client utilizes standard tools like favorite collections and custom inquiry messages. Conversely, a certified business partner manages enterprise metrics, localized tax certifications, and dedicated dealership storefront banners.


**Live Website Interface Reference:**


<img width="311" height="834" alt="image" src="https://github.com/user-attachments/assets/a5b2f02d-9f35-4b23-887a-4ec523d3072a" />


**Replicated C++ Infrastructure Snippet:**


<img width="456" height="630" alt="image" src="https://github.com/user-attachments/assets/fdf17c52-7fef-4e29-8f9f-ad976aaf504d" />


**Architectural Reasoning & Justification:**
To capture the platform's multi-tier actor schema while enforcing code reuse, we implemented an Inheritance Tree. Instead of copying base details (Name, Contact Email, Active Token Status) across separate classes, these live inside the primary User model. This structure permits specialized entities like Seller and Buyer to extend behaviors independently, modeling precise portal security limits.


### Feature C: Multi-Parameter Query Engine Filter Arrays
**Website Context:** The interface provides an adaptive filtering sidebar. Visitors can execute a broad string matching filter to locate inventory under a single uniform automotive label (e.g., "Suzuki"), or chain precise ceiling filters (e.g., "Max Budget: 20 Lacs") to instantly restrict broad arrays down to highly defined economic constraints.


**Live Website Interface Reference:**


<img width="236" height="854" alt="image" src="https://github.com/user-attachments/assets/adf4d430-6904-456c-aca2-5c157bb247a3" />
<img width="237" height="862" alt="image" src="https://github.com/user-attachments/assets/37756e17-4128-4d69-8b52-ed35bd8d34fd" />


**Replicated C++ Infrastructure Snippet:**


<img width="590" height="261" alt="image" src="https://github.com/user-attachments/assets/896889f1-fd97-446c-95d8-52eda980265f" />


**Architectural Reasoning & Justification:**
We replicate PakWheels' responsive search behavior through Compile-Time Polymorphism (Function Overloading). The framework handles multi-variate entry signatures by matching parameters during compilation. If a client enters a lone brand name, the compiler resolves the single-argument execution pathway; if an budget threshold is appended, it seamlessly paths execution to the dual-parameter filter array.


### Feature D: Interactive Saved Ads Mechanism (Favorites)
**Website Context:** When a buyer clicks the small heart icon or hits "Save Ad" on a specific car post, that particular item is instantly cataloged into their profile feed. This operation connects the specific listing information to the individual consumer's personal watchlist without duplicating the ad's main server footprint.

**Replicated C++ Infrastructure Snippet:**


<img width="506" height="189" alt="image" src="https://github.com/user-attachments/assets/87020874-6544-4ad6-b9e3-4e13143df7cf" />


**Architectural Reasoning & Justification:**
This mechanism maps to an Aggregation Relationship modeled through primitive pointer arrays. A saved listing asset survives entirely on its own within the core marketplace infrastructure; a customer profile merely retains a direct index memory connection to it (Listing*). If a buyer unfavorites an ad or wipes their local wishlist collection, the actual underlying physical advertisement listing data remains completely intact and accessible inside the system catalog
