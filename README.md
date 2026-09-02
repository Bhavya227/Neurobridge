# NeuroBridge Connect

Build NeuroBridge – AI-Powered Caregiver Assistive Dashboard

Create a modern, accessible, responsive healthcare web application called NeuroBridge.

NeuroBridge is an AI-powered assistive communication system for people with severe physical disabilities and paralysis. The system uses small voluntary muscle movements detected through an EMG sensor, processes the signals using Arduino + Python + Machine Learning, and converts recognized muscle patterns into meaningful actions.

The website should feel like a real working caregiver/patient monitoring platform, not a generic healthcare landing page.

The primary purpose of this website is:

Allow a patient to communicate using minimal muscle twitches.

Convert EMG/AI-detected twitch patterns into predefined commands.

Immediately notify the caregiver when assistance is required.

Distinguish between basic needs, caregiver calls, and emergencies.

Provide caregivers with a live dashboard showing patient status, detected commands, alerts, and device/system status.

1. CORE NEUROBRIDGE INTERACTION

The AI model receives EMG signals and classifies them into four patterns:

Relaxed

No action.

Single Twitch

Represents a Basic Need.

Examples:

Water

Food

Change position

Medication reminder

Washroom

Pain/discomfort

Other basic assistance

Double Twitch

Represents Call Caregiver.

The system should immediately create a caregiver call request.

Long Twitch

Represents Emergency.

The system should immediately trigger a high-priority emergency alert and caregiver notification.

Important:

The system must use a clear confirmation mechanism to reduce accidental activation.

For example:

Single Twitch:
AI detects → "Basic Need Detected" → display need selection/confirmation.

Double Twitch:
AI detects → "Caregiver Requested" → caregiver notification.

Long Twitch:
AI detects → "EMERGENCY DETECTED" → immediate high-priority alert with confirmation/cancel option where appropriate.

Do not make the interface confusing.

2. DESIGN DIRECTION

Create a premium medical-tech interface.

Visual style:

Clean

Minimal

Modern

Trustworthy

Accessible

High contrast

Large buttons

Large typography

Rounded cards

Soft shadows

Professional healthcare UI

Subtle AI/technology visual elements

Avoid:

Overly futuristic cyberpunk design

Excessive gradients

Excessive animations

Tiny text

Complicated navigation

Cluttered dashboards

The interface should feel appropriate for:

Hospitals

Rehabilitation centers

Smart homes

Caregiver environments

The project report specifically identifies hospitals, rehabilitation centres, smart homes, and personal healthcare environments as target deployment environments.

3. COLOR SYSTEM

Use a professional healthcare palette.

Primary:
Deep blue / medical blue

Secondary:
Teal / cyan

Success:
Green

Warning:
Amber/orange

Emergency:
Red

Background:
Very light gray / white

Emergency cards can use a subtle red background, but don't make the entire application red.

Maintain excellent WCAG-style contrast.

4. WEBSITE STRUCTURE

Create the following pages:

A. Landing Page

URL:

/

Hero section:

Title:

"NeuroBridge"

Subtitle:

"AI-Powered Assistive Communication for Greater Independence"

Supporting text:

"Turning small voluntary muscle movements into meaningful actions using EMG sensors and Artificial Intelligence."

Primary CTA:

"Open Caregiver Dashboard"

Secondary CTA:

"How NeuroBridge Works"

Hero visual:

Create a clean visual representation of:

Patient → EMG Sensor → Arduino → AI Model → Caregiver / Smart Devices

Show subtle animated signal lines.

Add a small badge:

"AI + EMG + Assistive Technology"

5. LANDING PAGE SECTIONS

Problem

Heading:

"Communication should never depend on physical strength."

Explain that paralysis patients may have difficulty speaking, moving freely, communicating needs, and interacting with their environment.

Mention that NeuroBridge is designed around minimal voluntary muscle activity.

Do not make unsupported medical claims.

Solution

Heading:

"Small Movement. Meaningful Action."

Explain:

EMG sensors detect electrical activity produced by muscle movement.

Arduino reads the analog signal.

The AI model classifies the signal pattern.

The recognized pattern triggers a predefined action.

Display this as four connected cards:

Detect

Process

Classify

Respond

6. TWITCH COMMAND SECTION

Create a highly visual section titled:

"Four Signals. Four States."

Show four cards:

Relaxed

Icon: activity/rest

Label:
"No Action"

Description:
"System is monitoring for intentional muscle activity."

Status color:
Neutral

Single Twitch

Icon:
Hand/finger movement

Label:
"Basic Need"

Description:
"Send a request for everyday assistance."

Button:
"View Basic Needs"

Double Twitch

Icon:
Bell / caregiver

Label:
"Call Caregiver"

Description:
"Request immediate caregiver assistance."

Button:
"Call Caregiver"

Long Twitch

Icon:
Emergency / alert

Label:
"Emergency"

Description:
"Trigger a high-priority emergency alert."

Button:
"Emergency Alert"

Make the Long Twitch card visually prominent.

7. CAREGIVER DASHBOARD

Create a main dashboard at:

/dashboard

This is the most important page.

The dashboard should contain:

Top Navigation

Logo:
NeuroBridge

Navigation:

Dashboard

Patient

Signals

Alerts

Devices

History

Settings

Right side:

System status

Caregiver profile

Notification icon

8. DASHBOARD HEADER

Show:

"Good morning, Caregiver"

Patient selector:

"Patient: Demo Patient"

Connection status:

● System Connected

Show:

EMG Sensor: Connected

Arduino: Connected

AI Model: Ready

Network: Connected

Use green indicators for connected devices.

If disconnected, use amber/red indicators.

9. LIVE PATIENT STATUS

Create a large card:

"Live Patient Status"

Display:

Patient Status:
"Monitoring"

Current Signal:
"Relaxed"

AI Prediction:
"Relaxed"

Confidence:
"98%"

Last Activity:
"Just now"

Connection:
"Stable"

Add a live-looking EMG waveform visualization.

The waveform should animate subtly.

Do not make the animation distracting.

10. REAL-TIME EMG SIGNAL PANEL

Create a large chart titled:

"Real-Time EMG Signal"

Display:

Signal amplitude

Time

Current signal state

Detection threshold

Add controls:

[Start Monitoring]

[Pause Monitoring]

[Reset]

The chart should visually resemble a real EMG signal.

Use simulated data in the frontend if no hardware/API is connected.

Clearly label simulated data:

"Demo / Simulated Signal"

Never pretend that simulated data is real patient data.

11. AI PREDICTION PANEL

Create a card:

"AI Signal Classification"

Display four classes:

Relaxed
Single Twitch
Double Twitch
Long Twitch

Show probability bars:

Relaxed 98%
Single Twitch 1%
Double Twitch 0.5%
Long Twitch 0.5%

These values should update dynamically in demo mode.

Highlight the currently detected class.

Example:

Current Prediction:
DOUBLE TWITCH

Confidence:
94%

Action:
CALL CAREGIVER

12. BASIC NEED SYSTEM

When Single Twitch is detected, show a panel:

"Basic Need Detected"

Allow caregiver/patient interface to display:

Water
Food
Medication
Washroom
Change Position
Pain / Discomfort
Other

Each should be a large accessible button.

Use icons.

Example:

💧 Water

🍽 Food

💊 Medication

🚻 Washroom

🛏 Change Position

⚠ Pain / Discomfort

When a need is selected:

Create a notification:

"Patient requested: Water"

Show timestamp.

Add:

[Acknowledge]

[Mark Resolved]

13. CAREGIVER CALL SYSTEM

When Double Twitch is detected:

Immediately show a caregiver request card.

Title:

"CARE GIVER REQUEST"

Message:

"Patient has requested caregiver assistance."

Show:

Patient name

Room

Time

Detected signal:
Double Twitch

Confidence

Status:
Waiting for response

Buttons:

[Accept Request]

[Dismiss]

When Accept Request is clicked:

Status becomes:

"Caregiver Responding"

Show timer:

"Response time: 00:12"

Then:

"Caregiver is responding to the request."

14. EMERGENCY SYSTEM

When Long Twitch is detected:

Create a full-width emergency alert at the top of the dashboard.

Title:

"EMERGENCY ALERT"

Message:

"Long muscle contraction detected. Immediate assistance may be required."

Display:

Patient
Room
Time
Signal
AI confidence
Alert ID

Buttons:

[ACKNOWLEDGE EMERGENCY]

[CALL CAREGIVER]

[MARK AS RESPONDING]

Use a strong red emergency visual hierarchy.

Add a pulsing emergency indicator, but keep it professional.

If this is a demo application, don't actually call emergency services.

Instead use:

"Emergency notification sent to assigned caregiver."

15. ALERT CENTER

Create:

/alerts

Show alerts in chronological order.

Each alert should contain:

Type
Patient
Signal
Time
Status
Action

Types:

Basic Need
Caregiver Request
Emergency

Statuses:

New
Acknowledged
Responding
Resolved

Add filters:

All
Emergency
Caregiver
Basic Need
Resolved

Add search.

Emergency alerts should remain visually prominent.

16. ALERT HISTORY

Create:

/history

Display a timeline/table.

Example:

10:42 AM
Single Twitch
Basic Need – Water
Resolved

10:38 AM
Double Twitch
Caregiver Request
Acknowledged

10:15 AM
Long Twitch
Emergency Alert
Responding

Include:

Date
Time
Signal
Detected Action
Confidence
Response Time
Status

Add date filters.

17. PATIENT PROFILE

Create:

/patient

Show:

Patient profile card

Name:
Demo Patient

Patient ID:
NB-DEMO-001

Room:
Room 204

Status:
Currently Monitoring

Assigned Caregiver:
Demo Caregiver

System:

EMG Sensor
Arduino
AI Model

Show connection status.

Do not collect unnecessary sensitive medical information.

Add a clear notice:

"Demo patient profile — no real medical data."

18. DEVICE MONITORING

Create:

/devices

Show hardware components based on the NeuroBridge architecture:

EMG Sensor

Status:
Connected

Signal:
Stable

Arduino Uno

Status:
Connected

Serial:
Active

AI Model

Status:
Ready

Model:
Random Forest

Network

Status:
Connected

Also show:

Last communication
Signal quality
Data stream status

Use realistic simulated values.

19. AI MODEL PAGE

Create:

/ai-model

Title:

"AI Signal Classification"

Explain the pipeline visually:

EMG Signal
↓
Noise Filtering
↓
Normalization
↓
Feature Extraction
↓
AI Classification
↓
Command
↓
Action

Show model options:

Logistic Regression
Random Forest

Mark:

"Preferred Model: Random Forest"

According to the NeuroBridge report, Random Forest is preferred because it provides better noise handling, generalisation, and reduced overfitting for noisy EMG data.

Show evaluation metrics:

Accuracy
Precision
Recall
Confusion Matrix

Use demo/example values only.

Clearly label them as:

"Prototype / Demo Metrics"

Do not fabricate real clinical performance.

20. SIGNAL STABILIZATION

Create a section:

"Signal Stabilization"

Explain the three techniques used in the NeuroBridge design:

Moving Average Filtering

Threshold Validation

Cooldown Timer

Display them as three cards.

Moving Average:
"Smooths short-term signal fluctuations."

Threshold Validation:
"Confirms that a signal exceeds the required activation level."

Cooldown Timer:
"Prevents repeated triggers from a sustained contraction."

Add status indicators:

Filtering: Active
Threshold Validation: Active
Cooldown: Active

This reflects the stabilization approach described in the project report.

21. SMART HOME CONTROL

Create:

/controls

Show smart-device cards:

Light
Fan
Alarm
Other Device

Example controls:

Light:
OFF / ON

Fan:
OFF / ON

Alarm:
OFF / ON

For demo purposes, allow the caregiver to control these devices from the dashboard.

Add:

"Demo Mode"

Explain:

"Device controls are simulated until connected to physical IoT hardware."

The NeuroBridge report identifies smart-home control such as lights, fans, alarms, and connected appliances as an application area.

22. PATIENT COMMUNICATION PANEL

Create:

/communication

Large accessible buttons:

"I Need Water"

"I Need Food"

"I Need Help"

"I Need to Change Position"

"I'm in Pain"

"Call Caregiver"

"Emergency"

This page should be extremely simple and accessible.

Use:

Huge buttons

Large icons

High contrast

Minimal text

Clear feedback after every selection

Add voice feedback optionally:

"Request sent."

But do not require voice input because the target users may have speech limitations.

23. SETTINGS

Create:

/settings

Sections:

Patient Settings
Caregiver Settings
Signal Settings
Notification Settings
Device Settings
Accessibility

Accessibility options:

Large Text
High Contrast
Reduce Animation
Dark Mode
Sound Notifications
Vibration/visual notification

Signal settings:

Detection threshold
Cooldown duration
Confidence threshold

Make it clear these are prototype configuration settings.

24. NOTIFICATION SYSTEM

Implement toast notifications.

Examples:

"Basic need request received."

"Caregiver has been notified."

"Emergency alert triggered."

"Request acknowledged."

"Device disconnected."

"EMG signal unstable."

Emergency notifications should be visually distinct.

25. DEMO MODE

This is extremely important.

Since the website may initially be built without actual Arduino/EMG hardware integration, create a fully functional Demo Mode.

Add a toggle:

"Demo Mode: ON"

Create a demo signal simulator.

Buttons:

[Simulate Relaxed]

[Simulate Single Twitch]

[Simulate Double Twitch]

[Simulate Long Twitch]

When the user clicks:

Simulate Single Twitch:

→ AI prediction changes to Single Twitch
→ Basic Need interface appears
→ Activity log updates

Simulate Double Twitch:

→ Caregiver request created
→ Alert appears
→ Notification appears

Simulate Long Twitch:

→ Emergency alert appears
→ Emergency sound/visual indicator appears
→ Alert history updates

This will allow the complete website to be demonstrated during the hackathon even before physical hardware is connected.

26. HARDWARE INTEGRATION ARCHITECTURE

Prepare the frontend architecture so it can later connect to the actual NeuroBridge system.

Expected future data flow:

EMG Sensor
→ Arduino Uno
→ Serial Communication
→ Python
→ Signal Processing
→ ML Model
→ API/WebSocket
→ NeuroBridge Dashboard
→ Caregiver Notification

Create a clean service layer so simulated data can later be replaced with a real API.

Use mock service functions such as:

getDeviceStatus()

getCurrentEMGSignal()

getPrediction()

sendCaregiverAlert()

sendEmergencyAlert()

getAlertHistory()

getPatientStatus()

Do not hardcode the architecture in UI components.

27. REAL-TIME COMMUNICATION

Structure the application so WebSocket support can be added later.

Create a mock real-time event system.

Example event:

{
"signal": "double_twitch",
"confidence": 0.94,
"timestamp": "...",
"action": "call_caregiver"
}

Another:

{
"signal": "long_twitch",
"confidence": 0.97,
"timestamp": "...",
"action": "emergency"
}

The frontend should react immediately to these events.

28. DATA MODEL

Use a simple structure for:

Patient

Caregiver

SignalEvent

Alert

Device

NeedRequest

Example SignalEvent:

id
signalType
confidence
timestamp
action
status

Signal types:

relaxed
single_twitch
double_twitch
long_twitch

Actions:

none
basic_need
call_caregiver
emergency

29. ACCESSIBILITY

This project is specifically for people with severe physical disabilities.

Therefore accessibility is a core requirement.

Implement:

Large clickable areas

Keyboard accessibility

High contrast

Screen-reader-friendly labels

Clear focus states

Minimal interaction steps

No tiny buttons

No essential action based only on color

Clear icons + text

Reduced motion option

Large emergency button

Simple navigation

The patient communication page should be usable with minimal interaction.

30. SAFETY UX

This is an assistive support prototype, not a certified medical device.

Include a small footer disclaimer:

"NeuroBridge is an assistive technology prototype and is not a replacement for professional medical care or certified medical devices."

For emergency alerts:

Do not claim that the application automatically contacts hospitals, ambulances, police, or emergency services unless an actual integration exists.

Use:

"Emergency alert sent to assigned caregiver."

for the prototype.

31. PRIVACY

Create a privacy-conscious design.

Do not expose unnecessary patient information.

Include:

"Patient biosignal data should be handled securely and only accessed by authorized users."

Add role-based access concept:

Patient
Caregiver
Administrator

For the prototype, authentication can be simulated.

32. RESPONSIVE DESIGN

The website must work perfectly on:

Desktop
Laptop
Tablet
Mobile

Caregiver dashboard:

Desktop:
Sidebar + dashboard

Mobile:
Bottom navigation or hamburger menu

Patient communication interface:

Mobile-first

Large buttons occupying most of the screen.

Emergency interface:

Extremely clear on mobile.

33. TECHNOLOGY

Use a modern frontend stack supported by Lovable.

Preferred:

React
TypeScript
Tailwind CSS
shadcn/ui
Lucide icons
Recharts for charts

Use clean reusable components.

Suggested component structure:

components/
Dashboard/
EMGChart/
SignalStatus/
AlertCard/
EmergencyAlert/
CaregiverRequest/
BasicNeedPanel/
DeviceStatus/
AIClassification/
PatientStatus/
Navigation/

services/
mockNeuroBridgeService
signalSimulator
notificationService

pages/
Landing
Dashboard
Patient
Alerts
History
Devices
AIModel
Controls
Communication
Settings

34. DASHBOARD LAYOUT

Desktop layout:

Sidebar
|
| Dashboard
| Patient
| Communication
| Alerts
| Devices
| AI Model
| Controls
| History
| Settings

Main:

Top Header

↓
Emergency Alert if active

↓
Patient Status + System Status

↓
Real-Time EMG Chart

↓
AI Prediction + Signal Classes

↓
Basic Need / Caregiver / Emergency Actions

↓
Recent Activity

Right/secondary section:

Device Status
Alert Summary
Connection Status

35. LANDING PAGE BRANDING

Use:

Logo:
NeuroBridge

Tagline:

"Small Signals. Greater Independence."

Alternative supporting phrase:

"Connecting muscle activity to meaningful action."

Do not overuse medical imagery.

Use subtle illustrations of:

Patient

EMG sensor

AI processing

Caregiver

The visual identity should communicate:

Human + Technology + Independence.

36. MICRO-INTERACTIONS

Add subtle animations:

Signal waveform movement

Connection status pulse

Alert appearing

Notification slide-in

AI prediction transition

Button feedback

For emergency:

Use a subtle pulse.

Provide "Reduce Motion" accessibility option.

37. DEMO FLOW FOR HACKATHON

The website must support this demonstration:

Step 1:
Open Dashboard.

Step 2:
Show:
System Connected
EMG Connected
Arduino Connected
AI Model Ready

Step 3:
Click:

"Simulate Single Twitch"

Website displays:

"Basic Need Detected"

Select:

"Water"

Dashboard displays:

"Patient requested Water."

Step 4:
Click:

"Simulate Double Twitch"

Website displays:

"Caregiver Requested"

Caregiver accepts request.

Step 5:
Click:

"Simulate Long Twitch"

Website immediately displays:

"EMERGENCY ALERT"

Caregiver receives emergency notification.

Step 6:
Open History.

Show all three events.

Step 7:
Open AI Model page.

Show:

EMG
→ Filtering
→ Feature Extraction
→ Random Forest
→ Classification
→ Action

Step 8:
Open Devices.

Show:

EMG Sensor
Arduino
AI Model
Network

This should create a complete end-to-end hackathon demonstration.

38. IMPORTANT FUNCTIONAL RULES

Implement these exact command mappings:

RELAXED
→ No action

SINGLE TWITCH
→ Basic Need

DOUBLE TWITCH
→ Call Caregiver

LONG TWITCH
→ Emergency Alert / Call Help

The command mapping must be configurable in settings, but these should be the default values.

Prevent duplicate triggers using a cooldown mechanism.

Do not trigger the same alert repeatedly while the same signal remains active.

Require confidence threshold validation before triggering an action.

Show the confidence score for every prediction.

39. ERROR STATES

Create realistic system states:

EMG disconnected

Arduino disconnected

AI model unavailable

Network disconnected

Low signal quality

Low prediction confidence

Emergency alert failed

Caregiver unavailable

For example:

"EMG Sensor Disconnected"

"Check sensor connection before continuing."

Provide:

[Retry Connection]

Do not hide system failures.

40. FINAL PRODUCT FEEL

The finished product should look like a combination of:

Healthcare dashboard

AI monitoring system

Assistive communication interface

Caregiver alert system

Smart-home control platform

It should be visually impressive enough for a Smart India Hackathon demonstration but technically structured enough that the frontend can later be connected to the actual Arduino + Python + ML pipeline.

Most importantly:

The website must demonstrate that NeuroBridge converts minimal muscle activity into useful human assistance.

Core story:

Patient performs tiny muscle movement
↓
EMG detects it
↓
Arduino reads signal
↓
AI classifies pattern
↓
NeuroBridge interprets command
↓
Caregiver receives meaningful request
↓
Patient gets assistance

Build the complete responsive application with realistic demo data, working navigation, functional simulated signal detection, alert creation, caregiver acknowledgement, history tracking, device monitoring, AI classification visualization, and accessibility features.

Do not create a static mockup.

Make the buttons and interactions actually work in the browser.

This project was built with [Lovable](https://lovable.dev).

**Live app**: https://mind-muscle-bridge.lovable.app

## Build with Lovable

Continue developing this project in the [Lovable editor](https://lovable.dev/projects/eab5c24e-efe7-4488-8966-90d16cd0ebeb).

- **Ship faster**: describe what you want to build and Lovable handles the code.
- **Stay in sync**: every change made in Lovable is committed straight to this repository.
- **Full ownership**: this code is yours. Push to `main` on GitHub and your changes sync back into Lovable, ready for your next prompt.

## Development

Prefer working locally? You need Node.js and npm — [install with nvm](https://github.com/nvm-sh/nvm#installing-and-updating).

```sh
git clone <this-repository-url>
cd <repository-name>
npm i
npm run dev
```
