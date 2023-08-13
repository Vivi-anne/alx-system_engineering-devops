## 0x19. Postmortem ##

Any software system will eventually fail, and that failure can come stem from a wide range of possible factors: bugs, traffic spikes, security issues, hardware failures, natural disasters, human error… Failing is normal and failing is actually a great opportunity to learn and improve. Any great Software Engineer must learn from his/her mistakes to make sure that they won’t happen again. Failing is fine, but failing twice because of the same issue is not.

A postmortem is a tool widely used in the tech industry. After any outage, the team(s) in charge of the system will write a summary that has 2 main goals:
- To provide the rest of the company’s employees easy access to information detailing the cause of the outage. Often outages can have a huge impact on a company, so managers and executives have to understand what happened and how it will impact their work.
- And to ensure that the root cause(s) of the outage has been discovered and that measures are taken to make sure it will be fixed.


**Postmortem: Web Stack Outage Incident - August 10, 2023**

**Issue Summary:**
Duration: August 10, 2023, 3:30 PM - 5:15 PM (UTC)
Impact: Web Application Unavailability, 25% of Users Affected
Root Cause: Database Connection Pool Exhaustion

**Timeline:**
- 3:30 PM: Issue detected as monitoring system triggered alerts for increased latency.
- 3:35 PM: Incident response team alerted.
- 3:47 PM: Investigation and root cause analysis initiated.
- 4:OO PM: Mitigation actions executed.
- 4:45 PM: Service restored and confirmed operational.
- 5:15 PM: Follow-up actions planned.

**Root Cause and Resolution:**
**Root Cause:** The root cause of the outage was an incorrect configuration of the database connection pooling settings. The connection pool was set to a lower value than required by the increasing traffic, causing the available connections to be exhausted quickly. As a result, new incoming requests were delayed or rejected.

**Resolution:** To address the issue, the connection pool settings were reconfigured to increase the maximum allowed connections, effectively accommodating the current traffic load. Additionally, connection timeout settings were optimized to ensure timely release of unused connections back to the pool. These adjustments prevented connection exhaustion and improved overall application performance.

**Corrective and Preventative Measures:**
**Improvements/Fixes:**
1. Implement automated load testing during continuous integration to catch resource-related regressions early.
2. Enhance monitoring and alerts for abnormal database connection usage patterns.
3. Establish a comprehensive incident response plan involving database administrators and network experts.

**Tasks to Address the Issue:**
1. Update connection pool settings to ensure a sufficient number of connections are available during peak load.
2. Deploy a database connection monitoring tool to track connection usage in real-time.
3. Develop a playbook for diagnosing and addressing connection-related issues, including clear steps for adjusting settings.
4. Conduct a thorough review of the application's resource consumption patterns to identify any other potential bottlenecks.
5. Enhance documentation and training for engineers on best practices for configuring and managing connection pools.

**Lessons Learned:**
This incident highlighted the critical importance of proper resource configuration in maintaining application stability. It also emphasized the need for collaborative cross-team communication during troubleshooting. By implementing proactive monitoring and refining incident response processes, we aim to mitigate similar issues in the future and enhance the overall reliability of our web application.

**Conclusion:**
This postmortem report provides insights into the service outage incident, its impact, root causes, and the steps taken to address it. By implementing the recommended measures, we aim to prevent similar incidents, enhance our service's reliability, and improve our incident response processes.
