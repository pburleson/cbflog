    /*
     * CFLog is a singleton logging object for more powerful logging in 
     * your cocoa projects
     *
     * Permission is hereby granted, free of charge, to any person
     * obtaining a copy of this software and associated documentation
     * files (the "Software"), to deal in the Software without
     * restriction, including without limitation the rights to use,
     * copy, modify, merge, publish, distribute, sublicense, and/or sell
     * copies of the Software, and to permit persons to whom the
     * Software is furnished to do so, subject to the following
     * conditions:
     * 
     * The above copyright notice and this permission notice shall be
     * included in all copies or substantial portions of the Software.
     * 
     * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
     * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
     * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
     * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
     * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
     * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
     * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
     * OTHER DEALINGS IN THE SOFTWARE.
     * 
     * Created by Camron Flanders on 2.23.09
     * Copyright 2009 camronflanders. All rights reserved.
     */


######NEW ###To Try:
- Build/Run the CFLogDemo project. Play with the settings in 
    CFLog.h to see how it affects logging.

####To use in your projects:
- Add CFLog.h and CFLog.m to your project.
- Add CFLog.h to the files where you will be logging.
- Define `_CFLOG_ENABLED`. You can uncomment the first config 
    line in CFLog.h or you can add it in your project settings.


I added `-D_CFLOG_ENABLED` to my Project Settings `Other C Flags` 
for my DEBUG project setting profile only. This means that my 
release and distro project profiles don't log anything, which 
is what I want. Logging is a fairly expensive process, so this 
should improve performance for your users.

####To Configure:
- Open CFLog.h and edit settings in the `CONFIGURATION` area. All 
    of the settings should be well documented.

CFLog can accept a couple arguments: Level and Override.
Debug levels are 1-5 `(DEBUG, INFO, WARNING, ERROR, CRITICAL)`
Override is nice, so you can turn the GLOBAL_SOFT_ENABLE setting 
to NO (off) and still log a few important things without 
commenting out all your logging statements.

I have included a few convenience functions that you can use:
`cfDebug, cfInfo, cfWarning, cfError, cfCritical` are mapped 
to a non-forced level-specific `cfLog` call.