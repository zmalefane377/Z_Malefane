# Weekly Page Style Guide

This document outlines the standard styles and structures to be used for all weekly documentation pages.

## General Layout

- **[Placeholder for General Layout Rules]**

## In-Page Navigation Box

The in-page navigation box provides quick access to different sections of the page. It should be implemented as follows:

### HTML Structure
```html
<!-- In-Page Navigation Box -->
<div class="inpage-nav-box">
    <h4>
        On This Page
        <button class="nav-toggle-button" aria-expanded="true" aria-controls="nav-list-weekX" title="Toggle navigation list">-</button>
    </h4>
    <ul id="nav-list-weekX">
        <li><a href="#introduction-weekX">Introduction</a></li>
        <li><a href="#process-documentation-weekX">Process Documentation</a></li>
        <li><a href="#1.Setting up GitX">1.Setting up Git</a></li>
        <li><a href="#2.Programming BasicsX">2.Programming Basics</a></li>
        <li><a href="#3.Web and Git hub PagesX">3.Web and Git hub Pages</a></li>
        <li><a href="4.Collaboration & PracticeX">4.Collaboration & Practice</a></li>
        <!-- Add more links as needed -->
    </ul>
</div>
```
*Note: The `id` for `ul` (e.g., `nav-list-weekX`) and the `aria-controls` attribute on the button should be unique if multiple nav boxes were on the same page. For individual weekly pages, a consistent pattern like `nav-list-weekN` (where N is the week number) is fine.*

### CSS Styling
```css
.inpage-nav-box {
    float: right;             /* Allows content to flow to its left initially */
    position: -webkit-sticky; /* For Safari compatibility */
    position: sticky;         /* Makes the element sticky on scroll */
    top: 20px;               /* Distance from viewport top when sticky */
    width: 220px;            /* Fixed width for the navigation box */
    margin-bottom: 1.5em;    /* Space below the box */
    background-color: #f8f8f8;
    border: 1px solid #e0e0e0;
    padding: 15px;
    border-radius: 8px;
    box-shadow: 0 2px 4px rgba(0,0,0,0.05);
    font-size: 0.9em;
    z-index: 1000;           /* Ensures it stays on top of other content */
}

.inpage-nav-box h4 {
    display: flex;           /* Align title and button */
    justify-content: space-between; /* Pushes button to the right */
    align-items: center;     /* Vertically align items */
    margin-top: 0;
    margin-bottom: 12px;
    font-size: 1em;
    font-weight: bold;
    color: #3d4449;
    border-bottom: 1px solid #e0e0e0;
    padding-bottom: 8px;
}

.nav-toggle-button {
    background: none;
    border: 1px solid #cccccc;
    color: #333333;
    cursor: pointer;
    font-size: 0.8em;
    font-weight: bold;
    padding: 1px 6px; /* Adjusted padding for a more compact button */
    border-radius: 4px;
    line-height: 1.2; /* Adjusted for better vertical centering of text */
    margin-left: 5px; /* Space between title and button */
}

.nav-toggle-button:hover {
    background-color: #e9e9e9;
    border-color: #bbbbbb;
}

.inpage-nav-box ul {
    list-style: none;
    padding: 0;
    margin: 0;
    /* Transition for smooth collapse/expand - optional */
    /* max-height: 500px; /* Adjust as needed, or use JS for height */
    /* overflow: hidden; */
    /* transition: max-height 0.3s ease-in-out; */
}

.inpage-nav-box ul.collapsed {
    display: none;
    /* For transition-based collapse: */
    /* max-height: 0; */
}

.inpage-nav-box ul li {
    margin-bottom: 8px;
}

.inpage-nav-box ul li:last-child {
    margin-bottom: 0;
}

.inpage-nav-box ul li a {
    text-decoration: none;
    color: #2980B9;
    display: block;
    padding: 3px 0;
}

.inpage-nav-box ul li a:hover {
    text-decoration: underline;
    color: #1c6691;
}

/* Responsive adjustments */
@media screen and (max-width: 1200px) {
    .inpage-nav-box {
        float: none;
        position: static;
        width: 100%;
        margin-bottom: 20px;
    }
    /* Toggle button might need adjustment on small screens if layout breaks */
}
```

### JavaScript for Toggling

The collapse/expand functionality for the in-page navigation box is handled by the global `assets/js/path-corrected-loader.js` script. This script automatically finds all `.inpage-nav-box` elements after content is loaded and attaches the necessary event listeners for the toggle button.

No additional JavaScript needs to be added to individual weekly HTML files for this feature to work.

Ensure that the HTML structure for the navigation box (including the `<h4>` with a `button.nav-toggle-button` and the `ul` with a unique ID like `nav-list-weekX`) is correctly implemented as per the HTML Structure section above. The `ul` can optionally have the `class="collapsed"` if it should be collapsed by default.

### Implementation Rules
1. **Placement**: The navigation box should be the first element inside the main content `<section>`
2. **Section IDs**: Each section heading must have a unique ID following the format `[topic]-weekX` (e.g., `introduction-week5`)
3. **Link Text**: Keep navigation items brief and descriptive
4. **Hierarchy**: Follow the page's content hierarchy in the navigation menu
5. **Responsive**: The box should collapse to full width on smaller screens

### Common Issues and Solutions
1. If the navigation doesn't stick:
   - Check for CSS conflicts
   - Ensure parent containers don't have `overflow: hidden`
   - Verify proper z-index values
2. If content overlaps:
   - Check float and margin settings
   - Verify responsive breakpoints
3. If links don't work:
   - Verify section IDs match link href values
   - Check for proper ID formatting

## Notes Tab Structure

- **Initial Content Order:** Every 'Notes' tab must begin with an Introduction section followed immediately by the Process Documentation section.
- **Headers:** Use appropriate headers (e.g., `<h2>` or `<header class="major">`) for 'Introduction' and 'Process Documentation'.
- **No Divider:** Do **not** place a horizontal rule (`<hr>`) or any other visual divider between the Introduction paragraph(s) and the 'Process Documentation' header.
- **Example Structure:**
  ```html
  <div id="Notes" class="tab-content active">
      <div>
          <header class="major">
              <h2>Introduction</h2>
          </header>
          <p>[Concise introductory text here...]</p>
          
          <header class="major">
              <h2>Process Documentation</h2>
          </header>
          <p>[Start of process documentation content...]</p>
          <!-- Rest of Notes content -->
      </div>
  </div>
  ```

## Typography

- **[Placeholder for Typography Rules]**
- **Major Headings:** For main section titles within the content (like 'Introduction', 'Process Documentation', 'Assignments', etc.), use an `<h2>` element wrapped within a `<header class="major">` tag. This provides the standard blue underline style.
  ```html
  <header class="major">
      <h2>Section Title</h2>
  </header>
  ```
- **Subheadings:** Use `<h3>`, `<h4>`, etc., for subsections as appropriate. These do not require the `<header class="major">` wrapper unless the specific underlined style is desired for emphasis.

## Images

- **[Placeholder for Image Styling Rules]**
- **Full-Width Images:** For images intended to span the full width of the content container (and resize with it), wrap the `<img>` tag in `<span class="image fit">` or `<span class="image main">`. 
    - Use `<span class="image main">` typically for the primary "hero" image near the top of the page.
    - Use `<span class="image fit">` for other single images within the content flow that should take full width.
    - The `<img>` tag itself should not need explicit width/height attributes when used with these classes, as the CSS handles sizing.
- **Inline/Floating Images:** For images floating left/right or intended to sit alongside text, use `<span class="image left">` or `<span class="image right">`. These have a default `max-width: 40%`.
- **Column Images:** Images placed within columns (`<div class="col-X">`) should typically use `<span class="image fit">` to fill the column width.
- **Captions:** Add captions below images using a paragraph with the class `image-caption`: `<p class="image-caption">Your caption here</p>`.
- **Captions:** All single full-width images (`.image.main`, `.image.fit`) and potentially column/floating images should have a caption directly below them. Implement captions using a paragraph with the class `image-caption`, like so: `<p class="image-caption">Your caption here</p>`. This class ensures the text is centered, italicized, and slightly smaller than the body text.

## Code Blocks

- **[Placeholder for Code Block Styling Rules]**

## Tabs

- **[Placeholder for Tab Structure/Style Rules]**

## Details/Summary Elements

- **Usage:** Use `<details>` and `<summary>` tags to create collapsible content sections (dropdowns).
- **Open by Default:** All `<details>` elements **must** include the `open` attribute to ensure they are expanded by default when the page loads.
- **Summary Styling:**
    - Increase font size using `<span style="font-size: 1.4em;">` around the summary content
    - Format title using a consistent pattern, e.g., `<b>Details</b> of circuit elements`
- **Content Container Styling:**
    - Apply these styles to the first div inside the details element:
    ```css
    margin-left: 20px; 
    border: 1px solid #bbbbbb; 
    border-radius: 4px; 
    padding: 18px; 
    background-color: #ffffff;
    ```
- **Example Structure:**
  ```html
  <details>
      <summary><span style="font-size: 1.4em;"><b>Details</b> of circuit elements</span></summary>
      <br>
      <div style="margin-left: 20px; border: 1px solid #bbbbbb; border-radius: 4px; padding: 18px; background-color: #ffffff;">
          <p>Detailed content goes here...</p>
          <!-- More content -->
      </div>
  </details>
  ```
- **Legacy Format** (Not preferred for new content, but may appear in older sections):
  ```html
  <details open>
      <summary><b>Design</b> (Creating a custom PCB layout for the sensor integration)</summary>
      <div>
          <p>Detailed content for Design step goes here...</p>
          <!-- More content -->
      </div>
  </details>
  ```

## Quick Summary Box

- **Purpose:** Provides a consistent, high-level overview at the start of each weekly page.
- **HTML Structure:** Use a `<div class="box">` element containing a `<header class="major">` which wraps an `<h3>Quick Summary</h3>` heading, followed by an unordered list `<ul class="alt">`.
- **List Item Format:** Each list item `<li>` within the `<ul class="alt">` must start with a `<strong>` tag containing the subheading label followed by a colon, then the corresponding text. Example: `<li><strong>Skills Learned:</strong> PCB milling, ...</li>`
- **Standard Subheadings:** The following subheadings must be included in this specific order:
    1.  Skills Learned
    2.  Digital Tools and Software Used
    3.  Hardware Used
    4.  Weekly Class Resources
    5.  Topics
    6.  Key Concepts
    7.  Challenges Faced
- **Example:**
  ```html
  <div class="box">
      <header class="major">
          <h3>Quick Summary</h3>
      </header>
      <ul class="alt">
          <li><strong>Skills Learned:</strong> [Description]</li>
          <li><strong>Digital Tools and Software Used:</strong> [Description]</li>
          <li><strong>Topics:</strong> [Description]</li>
          <li><strong>Key Concepts:</strong> [Description]</li>
          <li><strong>Challenges Faced:</strong> [Description]</li>
      </ul>
  </div>
  ```

## Other Components

- **[Placeholder for other component rules, e.g., Boxes, Lists]** s