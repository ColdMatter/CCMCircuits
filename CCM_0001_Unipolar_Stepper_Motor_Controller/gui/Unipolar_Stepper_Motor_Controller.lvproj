<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="14008000">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="CCM_0001_Unipolar_Stepper_Motor_Controller" Type="Folder" URL="../../..">
			<Property Name="NI.DISK" Type="Bool">true</Property>
		</Item>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="VISA Configure Serial Port" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Configure Serial Port"/>
				<Item Name="VISA Configure Serial Port (Instr).vi" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Configure Serial Port (Instr).vi"/>
				<Item Name="VISA Configure Serial Port (Serial Instr).vi" Type="VI" URL="/&lt;vilib&gt;/Instr/_visa.llb/VISA Configure Serial Port (Serial Instr).vi"/>
			</Item>
		</Item>
		<Item Name="Build Specifications" Type="Build">
			<Item Name="Executable Builder" Type="EXE">
				<Property Name="App_copyErrors" Type="Bool">true</Property>
				<Property Name="App_INI_aliasGUID" Type="Str">{95D788FB-22EA-4751-BE3E-C03B5431BD17}</Property>
				<Property Name="App_INI_GUID" Type="Str">{E07679E0-4A8C-4B8F-B04F-267A1001702D}</Property>
				<Property Name="App_serverConfig.httpPort" Type="Int">8002</Property>
				<Property Name="Bld_autoIncrement" Type="Bool">true</Property>
				<Property Name="Bld_buildCacheID" Type="Str">{D4F3DD7E-FB5B-4907-8E80-B830719D0CF0}</Property>
				<Property Name="Bld_buildSpecName" Type="Str">Executable Builder</Property>
				<Property Name="Bld_excludeInlineSubVIs" Type="Bool">true</Property>
				<Property Name="Bld_excludeLibraryItems" Type="Bool">true</Property>
				<Property Name="Bld_excludePolymorphicVIs" Type="Bool">true</Property>
				<Property Name="Bld_localDestDir" Type="Path">../Executable_Builds</Property>
				<Property Name="Bld_localDestDirType" Type="Str">relativeToProject</Property>
				<Property Name="Bld_modifyLibraryFile" Type="Bool">true</Property>
				<Property Name="Bld_previewCacheID" Type="Str">{B843C19D-79EF-4BB5-8DB4-0A42391EE42B}</Property>
				<Property Name="Bld_version.build" Type="Int">21</Property>
				<Property Name="Bld_version.major" Type="Int">1</Property>
				<Property Name="Destination[0].destName" Type="Str">Unipolar_Stepper_Motor_Controller.exe</Property>
				<Property Name="Destination[0].path" Type="Path">../Executable_Builds/Executable Builder.exe</Property>
				<Property Name="Destination[0].path.type" Type="Str">relativeToProject</Property>
				<Property Name="Destination[0].preserveHierarchy" Type="Bool">true</Property>
				<Property Name="Destination[0].type" Type="Str">App</Property>
				<Property Name="Destination[1].destName" Type="Str">Support Directory</Property>
				<Property Name="Destination[1].path" Type="Path">../Executable_Builds/data</Property>
				<Property Name="Destination[1].path.type" Type="Str">relativeToProject</Property>
				<Property Name="DestinationCount" Type="Int">2</Property>
				<Property Name="Exe_iconItemID" Type="Ref">/My Computer/CCM_0001_Unipolar_Stepper_Motor_Controller/RevA/gui/MotorIcon.ico</Property>
				<Property Name="Source[0].itemID" Type="Str">{D2D3AE4C-157C-46E8-8531-4BDCF6D6F55F}</Property>
				<Property Name="Source[0].type" Type="Str">Container</Property>
				<Property Name="Source[1].destinationIndex" Type="Int">0</Property>
				<Property Name="Source[1].itemID" Type="Ref">/My Computer/CCM_0001_Unipolar_Stepper_Motor_Controller/RevA/gui/Unipolar_Stepper_Motor_Controller.vi</Property>
				<Property Name="Source[1].sourceInclusion" Type="Str">TopLevel</Property>
				<Property Name="Source[1].type" Type="Str">VI</Property>
				<Property Name="SourceCount" Type="Int">2</Property>
				<Property Name="TgtF_companyName" Type="Str">Imperial College London</Property>
				<Property Name="TgtF_fileDescription" Type="Str">This is a GUI to be used with the stepper motor control circuit CCM_0001.  -Noah Fitch</Property>
				<Property Name="TgtF_internalName" Type="Str">Executable Builder</Property>
				<Property Name="TgtF_legalCopyright" Type="Str">Copyright © 2015 Imperial College London</Property>
				<Property Name="TgtF_productName" Type="Str">Executable Builder</Property>
				<Property Name="TgtF_targetfileGUID" Type="Str">{9C4EC0DC-43A3-49EE-9FA3-528690D45F01}</Property>
				<Property Name="TgtF_targetfileName" Type="Str">Unipolar_Stepper_Motor_Controller.exe</Property>
			</Item>
			<Item Name="Executable Only Installer" Type="Installer">
				<Property Name="Destination[0].name" Type="Str">Unipolar_Stepper_Motor_Controller</Property>
				<Property Name="Destination[0].parent" Type="Str">{3912416A-D2E5-411B-AFEE-B63654D690C0}</Property>
				<Property Name="Destination[0].tag" Type="Str">{A0FD48CD-57E6-4B7E-9BE4-0014171B99D2}</Property>
				<Property Name="Destination[0].type" Type="Str">userFolder</Property>
				<Property Name="Destination[1].name" Type="Str">bin</Property>
				<Property Name="Destination[1].parent" Type="Str">{A0FD48CD-57E6-4B7E-9BE4-0014171B99D2}</Property>
				<Property Name="Destination[1].tag" Type="Str">{7CC25654-BD7F-40E8-8501-915D74280AED}</Property>
				<Property Name="Destination[1].type" Type="Str">userFolder</Property>
				<Property Name="Destination[2].name" Type="Str">ftdi</Property>
				<Property Name="Destination[2].parent" Type="Str">{A0FD48CD-57E6-4B7E-9BE4-0014171B99D2}</Property>
				<Property Name="Destination[2].tag" Type="Str">{7D4A189D-D63C-4862-B44C-516F6FE87F09}</Property>
				<Property Name="Destination[2].type" Type="Str">userFolder</Property>
				<Property Name="Destination[3].name" Type="Str">documentation</Property>
				<Property Name="Destination[3].parent" Type="Str">{A0FD48CD-57E6-4B7E-9BE4-0014171B99D2}</Property>
				<Property Name="Destination[3].tag" Type="Str">{DE1A1EFF-42A5-4AC6-91BF-9C9B83D7447D}</Property>
				<Property Name="Destination[3].type" Type="Str">userFolder</Property>
				<Property Name="DestinationCount" Type="Int">4</Property>
				<Property Name="INST_author" Type="Str">Imperial College London</Property>
				<Property Name="INST_autoIncrement" Type="Bool">true</Property>
				<Property Name="INST_buildLocation" Type="Path">../gui/Installer_Builds/Partial</Property>
				<Property Name="INST_buildLocation.type" Type="Str">relativeToCommon</Property>
				<Property Name="INST_buildSpecName" Type="Str">Executable Only Installer</Property>
				<Property Name="INST_defaultDir" Type="Str">{A0FD48CD-57E6-4B7E-9BE4-0014171B99D2}</Property>
				<Property Name="INST_productName" Type="Str">Unipolar_Stepper_Motor_Controller_Installer</Property>
				<Property Name="INST_productVersion" Type="Str">1.0.24</Property>
				<Property Name="InstSpecBitness" Type="Str">32-bit</Property>
				<Property Name="InstSpecVersion" Type="Str">14018013</Property>
				<Property Name="MSI_arpCompany" Type="Str">Imperial College London</Property>
				<Property Name="MSI_distID" Type="Str">{1960A2A7-52CA-4792-932C-19CA95B77743}</Property>
				<Property Name="MSI_osCheck" Type="Int">0</Property>
				<Property Name="MSI_upgradeCode" Type="Str">{9008363D-34A2-414E-942B-9FF4D9956B7F}</Property>
				<Property Name="RegDest[0].dirName" Type="Str">Software</Property>
				<Property Name="RegDest[0].dirTag" Type="Str">{DDFAFC8B-E728-4AC8-96DE-B920EBB97A86}</Property>
				<Property Name="RegDest[0].parentTag" Type="Str">2</Property>
				<Property Name="RegDestCount" Type="Int">1</Property>
				<Property Name="Source[0].dest" Type="Str">{7CC25654-BD7F-40E8-8501-915D74280AED}</Property>
				<Property Name="Source[0].File[0].dest" Type="Str">{7CC25654-BD7F-40E8-8501-915D74280AED}</Property>
				<Property Name="Source[0].File[0].name" Type="Str">Unipolar_Stepper_Motor_Controller.exe</Property>
				<Property Name="Source[0].File[0].tag" Type="Str">{9C4EC0DC-43A3-49EE-9FA3-528690D45F01}</Property>
				<Property Name="Source[0].name" Type="Str">Unipolar_Stepper_Motor_Controller.aliases</Property>
				<Property Name="Source[0].tag" Type="Ref">/My Computer/CCM_0001_Unipolar_Stepper_Motor_Controller/RevA/gui/Executable_Builds/Unipolar_Stepper_Motor_Controller.aliases</Property>
				<Property Name="Source[0].type" Type="Str">File</Property>
				<Property Name="Source[1].dest" Type="Str">{7CC25654-BD7F-40E8-8501-915D74280AED}</Property>
				<Property Name="Source[1].name" Type="Str">Unipolar_Stepper_Motor_Controller.exe</Property>
				<Property Name="Source[1].Shortcut[0].destIndex" Type="Int">1</Property>
				<Property Name="Source[1].Shortcut[0].name" Type="Str">Unipolar_Stepper_Motor_Controller</Property>
				<Property Name="Source[1].Shortcut[0].subDir" Type="Str"></Property>
				<Property Name="Source[1].ShortcutCount" Type="Int">1</Property>
				<Property Name="Source[1].tag" Type="Ref">/My Computer/CCM_0001_Unipolar_Stepper_Motor_Controller/RevA/gui/Executable_Builds/Unipolar_Stepper_Motor_Controller.exe</Property>
				<Property Name="Source[1].type" Type="Str">File</Property>
				<Property Name="Source[10].dest" Type="Str">{DE1A1EFF-42A5-4AC6-91BF-9C9B83D7447D}</Property>
				<Property Name="Source[10].name" Type="Str">KnownIssues.txt</Property>
				<Property Name="Source[10].tag" Type="Ref">/My Computer/CCM_0001_Unipolar_Stepper_Motor_Controller/RevA/KnownIssues.txt</Property>
				<Property Name="Source[10].type" Type="Str">File</Property>
				<Property Name="Source[2].dest" Type="Str">{7CC25654-BD7F-40E8-8501-915D74280AED}</Property>
				<Property Name="Source[2].File[0].dest" Type="Str">{7CC25654-BD7F-40E8-8501-915D74280AED}</Property>
				<Property Name="Source[2].File[0].name" Type="Str">Unipolar_Stepper_Motor_Controller.exe</Property>
				<Property Name="Source[2].File[0].tag" Type="Str">{9C4EC0DC-43A3-49EE-9FA3-528690D45F01}</Property>
				<Property Name="Source[2].name" Type="Str">Unipolar_Stepper_Motor_Controller.ini</Property>
				<Property Name="Source[2].tag" Type="Ref">/My Computer/CCM_0001_Unipolar_Stepper_Motor_Controller/RevA/gui/Executable_Builds/Unipolar_Stepper_Motor_Controller.ini</Property>
				<Property Name="Source[2].type" Type="Str">File</Property>
				<Property Name="Source[3].dest" Type="Str">{DE1A1EFF-42A5-4AC6-91BF-9C9B83D7447D}</Property>
				<Property Name="Source[3].File[0].dest" Type="Str">{A0FD48CD-57E6-4B7E-9BE4-0014171B99D2}</Property>
				<Property Name="Source[3].File[0].name" Type="Str">combined.hex</Property>
				<Property Name="Source[3].File[0].tag" Type="Ref"></Property>
				<Property Name="Source[3].name" Type="Str">documentation.pdf</Property>
				<Property Name="Source[3].tag" Type="Ref">/My Computer/CCM_0001_Unipolar_Stepper_Motor_Controller/RevA/documentation/build/documentation.pdf</Property>
				<Property Name="Source[3].type" Type="Str">File</Property>
				<Property Name="Source[4].dest" Type="Str">{7D4A189D-D63C-4862-B44C-516F6FE87F09}</Property>
				<Property Name="Source[4].File[0].dest" Type="Str">{A0FD48CD-57E6-4B7E-9BE4-0014171B99D2}</Property>
				<Property Name="Source[4].File[0].name" Type="Str">BOM.txt</Property>
				<Property Name="Source[4].File[0].tag" Type="Ref"></Property>
				<Property Name="Source[4].name" Type="Str">CDM v2.10.00 WHQL Certified.exe</Property>
				<Property Name="Source[4].runEXE" Type="Bool">true</Property>
				<Property Name="Source[4].tag" Type="Ref">/My Computer/CCM_0001_Unipolar_Stepper_Motor_Controller/RevA/ftdi/CDM v2.10.00 WHQL Certified.exe</Property>
				<Property Name="Source[4].type" Type="Str">File</Property>
				<Property Name="Source[5].dest" Type="Str">{7D4A189D-D63C-4862-B44C-516F6FE87F09}</Property>
				<Property Name="Source[5].File[0].dest" Type="Str">{A0FD48CD-57E6-4B7E-9BE4-0014171B99D2}</Property>
				<Property Name="Source[5].File[0].name" Type="Str">Unipolar_Stepper_Motor_Controller.aliases</Property>
				<Property Name="Source[5].File[0].tag" Type="Ref"></Property>
				<Property Name="Source[5].name" Type="Str">usbview.exe</Property>
				<Property Name="Source[5].tag" Type="Ref">/My Computer/CCM_0001_Unipolar_Stepper_Motor_Controller/RevA/ftdi/usbview.exe</Property>
				<Property Name="Source[5].type" Type="Str">File</Property>
				<Property Name="Source[6].dest" Type="Str">{7D4A189D-D63C-4862-B44C-516F6FE87F09}</Property>
				<Property Name="Source[6].File[0].dest" Type="Str">{A0FD48CD-57E6-4B7E-9BE4-0014171B99D2}</Property>
				<Property Name="Source[6].File[0].name" Type="Str">FIRMWARE.ASM</Property>
				<Property Name="Source[6].File[0].tag" Type="Ref"></Property>
				<Property Name="Source[6].name" Type="Str">FT_Prog.exe</Property>
				<Property Name="Source[6].tag" Type="Ref">/My Computer/CCM_0001_Unipolar_Stepper_Motor_Controller/RevA/ftdi/FT_Prog.exe</Property>
				<Property Name="Source[6].type" Type="Str">File</Property>
				<Property Name="Source[7].dest" Type="Str">{7D4A189D-D63C-4862-B44C-516F6FE87F09}</Property>
				<Property Name="Source[7].File[0].dest" Type="Str">{A0FD48CD-57E6-4B7E-9BE4-0014171B99D2}</Property>
				<Property Name="Source[7].File[0].name" Type="Str">CDM v2.10.00 WHQL Certified.exe</Property>
				<Property Name="Source[7].File[0].tag" Type="Ref"></Property>
				<Property Name="Source[7].name" Type="Str">FT_Prog-CmdLine.exe</Property>
				<Property Name="Source[7].tag" Type="Ref">/My Computer/CCM_0001_Unipolar_Stepper_Motor_Controller/RevA/ftdi/FT_Prog-CmdLine.exe</Property>
				<Property Name="Source[7].type" Type="Str">File</Property>
				<Property Name="Source[8].dest" Type="Str">{7D4A189D-D63C-4862-B44C-516F6FE87F09}</Property>
				<Property Name="Source[8].File[0].dest" Type="Str">{A0FD48CD-57E6-4B7E-9BE4-0014171B99D2}</Property>
				<Property Name="Source[8].File[0].name" Type="Str">CCM_0001_Documentation.tex</Property>
				<Property Name="Source[8].File[0].tag" Type="Ref"></Property>
				<Property Name="Source[8].name" Type="Str">stepper_ftdi_config.bat</Property>
				<Property Name="Source[8].tag" Type="Ref">/My Computer/CCM_0001_Unipolar_Stepper_Motor_Controller/RevA/ftdi/stepper_ftdi_config.bat</Property>
				<Property Name="Source[8].type" Type="Str">File</Property>
				<Property Name="Source[9].dest" Type="Str">{7D4A189D-D63C-4862-B44C-516F6FE87F09}</Property>
				<Property Name="Source[9].File[0].dest" Type="Str">{A0FD48CD-57E6-4B7E-9BE4-0014171B99D2}</Property>
				<Property Name="Source[9].File[0].name" Type="Str">bootloader.asm</Property>
				<Property Name="Source[9].File[0].tag" Type="Ref"></Property>
				<Property Name="Source[9].name" Type="Str">AN_124_User_Guide_For_FT_PROG.pdf</Property>
				<Property Name="Source[9].tag" Type="Ref">/My Computer/CCM_0001_Unipolar_Stepper_Motor_Controller/RevA/ftdi/AN_124_User_Guide_For_FT_PROG.pdf</Property>
				<Property Name="Source[9].type" Type="Str">File</Property>
				<Property Name="SourceCount" Type="Int">11</Property>
			</Item>
			<Item Name="Full Installer" Type="Installer">
				<Property Name="Destination[0].name" Type="Str">Unipolar_Stepper_Motor_Controller</Property>
				<Property Name="Destination[0].parent" Type="Str">{3912416A-D2E5-411B-AFEE-B63654D690C0}</Property>
				<Property Name="Destination[0].tag" Type="Str">{A0FD48CD-57E6-4B7E-9BE4-0014171B99D2}</Property>
				<Property Name="Destination[0].type" Type="Str">userFolder</Property>
				<Property Name="Destination[1].name" Type="Str">bin</Property>
				<Property Name="Destination[1].parent" Type="Str">{A0FD48CD-57E6-4B7E-9BE4-0014171B99D2}</Property>
				<Property Name="Destination[1].tag" Type="Str">{7CC25654-BD7F-40E8-8501-915D74280AED}</Property>
				<Property Name="Destination[1].type" Type="Str">userFolder</Property>
				<Property Name="Destination[2].name" Type="Str">ftdi</Property>
				<Property Name="Destination[2].parent" Type="Str">{A0FD48CD-57E6-4B7E-9BE4-0014171B99D2}</Property>
				<Property Name="Destination[2].tag" Type="Str">{7D4A189D-D63C-4862-B44C-516F6FE87F09}</Property>
				<Property Name="Destination[2].type" Type="Str">userFolder</Property>
				<Property Name="Destination[3].name" Type="Str">documentation</Property>
				<Property Name="Destination[3].parent" Type="Str">{A0FD48CD-57E6-4B7E-9BE4-0014171B99D2}</Property>
				<Property Name="Destination[3].tag" Type="Str">{DE1A1EFF-42A5-4AC6-91BF-9C9B83D7447D}</Property>
				<Property Name="Destination[3].type" Type="Str">userFolder</Property>
				<Property Name="DestinationCount" Type="Int">4</Property>
				<Property Name="DistPart[0].flavorID" Type="Str">DefaultFull</Property>
				<Property Name="DistPart[0].productID" Type="Str">{331B6132-FA2A-458D-828D-B0DA0237739A}</Property>
				<Property Name="DistPart[0].productName" Type="Str">NI LabVIEW Runtime 2014 SP1 f3</Property>
				<Property Name="DistPart[0].SoftDep[0].exclude" Type="Bool">false</Property>
				<Property Name="DistPart[0].SoftDep[0].productName" Type="Str">NI LabVIEW Runtime 2014 SP1 Non-English Support.</Property>
				<Property Name="DistPart[0].SoftDep[0].upgradeCode" Type="Str">{CAC8FA79-6D3D-4263-BB7B-1A706EF87C08}</Property>
				<Property Name="DistPart[0].SoftDep[1].exclude" Type="Bool">false</Property>
				<Property Name="DistPart[0].SoftDep[1].productName" Type="Str">NI ActiveX Container</Property>
				<Property Name="DistPart[0].SoftDep[1].upgradeCode" Type="Str">{1038A887-23E1-4289-B0BD-0C4B83C6BA21}</Property>
				<Property Name="DistPart[0].SoftDep[10].exclude" Type="Bool">false</Property>
				<Property Name="DistPart[0].SoftDep[10].productName" Type="Str">NI VC2010MSMs</Property>
				<Property Name="DistPart[0].SoftDep[10].upgradeCode" Type="Str">{EFBA6F9E-F934-4BD7-AC51-60CCA480489C}</Property>
				<Property Name="DistPart[0].SoftDep[11].exclude" Type="Bool">false</Property>
				<Property Name="DistPart[0].SoftDep[11].productName" Type="Str">NI mDNS Responder 14.0</Property>
				<Property Name="DistPart[0].SoftDep[11].upgradeCode" Type="Str">{9607874B-4BB3-42CB-B450-A2F5EF60BA3B}</Property>
				<Property Name="DistPart[0].SoftDep[12].exclude" Type="Bool">false</Property>
				<Property Name="DistPart[0].SoftDep[12].productName" Type="Str">NI Deployment Framework 2014</Property>
				<Property Name="DistPart[0].SoftDep[12].upgradeCode" Type="Str">{838942E4-B73C-492E-81A3-AA1E291FD0DC}</Property>
				<Property Name="DistPart[0].SoftDep[13].exclude" Type="Bool">false</Property>
				<Property Name="DistPart[0].SoftDep[13].productName" Type="Str">NI Error Reporting 2014</Property>
				<Property Name="DistPart[0].SoftDep[13].upgradeCode" Type="Str">{42E818C6-2B08-4DE7-BD91-B0FD704C119A}</Property>
				<Property Name="DistPart[0].SoftDep[2].exclude" Type="Bool">false</Property>
				<Property Name="DistPart[0].SoftDep[2].productName" Type="Str">NI Service Locator 14.0</Property>
				<Property Name="DistPart[0].SoftDep[2].upgradeCode" Type="Str">{B235B862-6A92-4A04-A8B2-6D71F777DE67}</Property>
				<Property Name="DistPart[0].SoftDep[3].exclude" Type="Bool">false</Property>
				<Property Name="DistPart[0].SoftDep[3].productName" Type="Str">NI System Web Server 14.5</Property>
				<Property Name="DistPart[0].SoftDep[3].upgradeCode" Type="Str">{FCF64B73-B7D4-4971-8F11-24BAF7CC3E6C}</Property>
				<Property Name="DistPart[0].SoftDep[4].exclude" Type="Bool">false</Property>
				<Property Name="DistPart[0].SoftDep[4].productName" Type="Str">Math Kernel Libraries</Property>
				<Property Name="DistPart[0].SoftDep[4].upgradeCode" Type="Str">{3BDD0408-2F90-4B42-9777-5ED1D4BE67A8}</Property>
				<Property Name="DistPart[0].SoftDep[5].exclude" Type="Bool">false</Property>
				<Property Name="DistPart[0].SoftDep[5].productName" Type="Str">NI Logos 14.0</Property>
				<Property Name="DistPart[0].SoftDep[5].upgradeCode" Type="Str">{5E4A4CE3-4D06-11D4-8B22-006008C16337}</Property>
				<Property Name="DistPart[0].SoftDep[6].exclude" Type="Bool">false</Property>
				<Property Name="DistPart[0].SoftDep[6].productName" Type="Str">NI TDM Streaming 14.0</Property>
				<Property Name="DistPart[0].SoftDep[6].upgradeCode" Type="Str">{4CD11BE6-6BB7-4082-8A27-C13771BC309B}</Property>
				<Property Name="DistPart[0].SoftDep[7].exclude" Type="Bool">false</Property>
				<Property Name="DistPart[0].SoftDep[7].productName" Type="Str">NI LabVIEW Web Server 2014</Property>
				<Property Name="DistPart[0].SoftDep[7].upgradeCode" Type="Str">{4A8BDBBB-DA1C-45C9-8563-74C034FBD357}</Property>
				<Property Name="DistPart[0].SoftDep[8].exclude" Type="Bool">false</Property>
				<Property Name="DistPart[0].SoftDep[8].productName" Type="Str">NI LabVIEW Real-Time NBFifo 2014</Property>
				<Property Name="DistPart[0].SoftDep[8].upgradeCode" Type="Str">{4372F3E3-5935-4012-93AB-B6710CE24920}</Property>
				<Property Name="DistPart[0].SoftDep[9].exclude" Type="Bool">false</Property>
				<Property Name="DistPart[0].SoftDep[9].productName" Type="Str">NI VC2008MSMs</Property>
				<Property Name="DistPart[0].SoftDep[9].upgradeCode" Type="Str">{FDA3F8BB-BAA9-45D7-8DC7-22E1F5C76315}</Property>
				<Property Name="DistPart[0].SoftDepCount" Type="Int">14</Property>
				<Property Name="DistPart[0].upgradeCode" Type="Str">{4722F14B-8434-468D-840D-2B0CD8CBD5EA}</Property>
				<Property Name="DistPartCount" Type="Int">1</Property>
				<Property Name="INST_author" Type="Str">Imperial College London</Property>
				<Property Name="INST_autoIncrement" Type="Bool">true</Property>
				<Property Name="INST_buildLocation" Type="Path">../gui/Installer_Builds/Full</Property>
				<Property Name="INST_buildLocation.type" Type="Str">relativeToCommon</Property>
				<Property Name="INST_buildSpecName" Type="Str">Full Installer</Property>
				<Property Name="INST_defaultDir" Type="Str">{A0FD48CD-57E6-4B7E-9BE4-0014171B99D2}</Property>
				<Property Name="INST_productName" Type="Str">Unipolar_Stepper_Motor_Controller_Installer</Property>
				<Property Name="INST_productVersion" Type="Str">1.0.24</Property>
				<Property Name="InstSpecBitness" Type="Str">32-bit</Property>
				<Property Name="InstSpecVersion" Type="Str">14018013</Property>
				<Property Name="MSI_arpCompany" Type="Str">Imperial College London</Property>
				<Property Name="MSI_autoselectDrivers" Type="Bool">true</Property>
				<Property Name="MSI_distID" Type="Str">{EC1CE904-973D-4473-A28F-BC7C34EE757C}</Property>
				<Property Name="MSI_osCheck" Type="Int">0</Property>
				<Property Name="MSI_upgradeCode" Type="Str">{B191752F-1F81-4185-9893-67EE703AAAE2}</Property>
				<Property Name="RegDest[0].dirName" Type="Str">Software</Property>
				<Property Name="RegDest[0].dirTag" Type="Str">{DDFAFC8B-E728-4AC8-96DE-B920EBB97A86}</Property>
				<Property Name="RegDest[0].parentTag" Type="Str">2</Property>
				<Property Name="RegDestCount" Type="Int">1</Property>
				<Property Name="Source[0].dest" Type="Str">{7CC25654-BD7F-40E8-8501-915D74280AED}</Property>
				<Property Name="Source[0].File[0].dest" Type="Str">{7CC25654-BD7F-40E8-8501-915D74280AED}</Property>
				<Property Name="Source[0].File[0].name" Type="Str">Unipolar_Stepper_Motor_Controller.exe</Property>
				<Property Name="Source[0].File[0].tag" Type="Str">{9C4EC0DC-43A3-49EE-9FA3-528690D45F01}</Property>
				<Property Name="Source[0].name" Type="Str">Unipolar_Stepper_Motor_Controller.aliases</Property>
				<Property Name="Source[0].tag" Type="Ref">/My Computer/CCM_0001_Unipolar_Stepper_Motor_Controller/RevA/gui/Executable_Builds/Unipolar_Stepper_Motor_Controller.aliases</Property>
				<Property Name="Source[0].type" Type="Str">File</Property>
				<Property Name="Source[1].dest" Type="Str">{7CC25654-BD7F-40E8-8501-915D74280AED}</Property>
				<Property Name="Source[1].name" Type="Str">Unipolar_Stepper_Motor_Controller.exe</Property>
				<Property Name="Source[1].Shortcut[0].destIndex" Type="Int">1</Property>
				<Property Name="Source[1].Shortcut[0].name" Type="Str">Unipolar_Stepper_Motor_Controller</Property>
				<Property Name="Source[1].Shortcut[0].subDir" Type="Str"></Property>
				<Property Name="Source[1].ShortcutCount" Type="Int">1</Property>
				<Property Name="Source[1].tag" Type="Ref">/My Computer/CCM_0001_Unipolar_Stepper_Motor_Controller/RevA/gui/Executable_Builds/Unipolar_Stepper_Motor_Controller.exe</Property>
				<Property Name="Source[1].type" Type="Str">File</Property>
				<Property Name="Source[10].dest" Type="Str">{DE1A1EFF-42A5-4AC6-91BF-9C9B83D7447D}</Property>
				<Property Name="Source[10].name" Type="Str">KnownIssues.txt</Property>
				<Property Name="Source[10].tag" Type="Ref">/My Computer/CCM_0001_Unipolar_Stepper_Motor_Controller/RevA/KnownIssues.txt</Property>
				<Property Name="Source[10].type" Type="Str">File</Property>
				<Property Name="Source[2].dest" Type="Str">{7CC25654-BD7F-40E8-8501-915D74280AED}</Property>
				<Property Name="Source[2].File[0].dest" Type="Str">{7CC25654-BD7F-40E8-8501-915D74280AED}</Property>
				<Property Name="Source[2].File[0].name" Type="Str">Unipolar_Stepper_Motor_Controller.exe</Property>
				<Property Name="Source[2].File[0].tag" Type="Str">{9C4EC0DC-43A3-49EE-9FA3-528690D45F01}</Property>
				<Property Name="Source[2].name" Type="Str">Unipolar_Stepper_Motor_Controller.ini</Property>
				<Property Name="Source[2].tag" Type="Ref">/My Computer/CCM_0001_Unipolar_Stepper_Motor_Controller/RevA/gui/Executable_Builds/Unipolar_Stepper_Motor_Controller.ini</Property>
				<Property Name="Source[2].type" Type="Str">File</Property>
				<Property Name="Source[3].dest" Type="Str">{DE1A1EFF-42A5-4AC6-91BF-9C9B83D7447D}</Property>
				<Property Name="Source[3].File[0].dest" Type="Str">{A0FD48CD-57E6-4B7E-9BE4-0014171B99D2}</Property>
				<Property Name="Source[3].File[0].name" Type="Str">combined.hex</Property>
				<Property Name="Source[3].File[0].tag" Type="Ref"></Property>
				<Property Name="Source[3].name" Type="Str">documentation.pdf</Property>
				<Property Name="Source[3].tag" Type="Ref">/My Computer/CCM_0001_Unipolar_Stepper_Motor_Controller/RevA/documentation/build/documentation.pdf</Property>
				<Property Name="Source[3].type" Type="Str">File</Property>
				<Property Name="Source[4].dest" Type="Str">{7D4A189D-D63C-4862-B44C-516F6FE87F09}</Property>
				<Property Name="Source[4].File[0].dest" Type="Str">{A0FD48CD-57E6-4B7E-9BE4-0014171B99D2}</Property>
				<Property Name="Source[4].File[0].name" Type="Str">BOM.txt</Property>
				<Property Name="Source[4].File[0].tag" Type="Ref"></Property>
				<Property Name="Source[4].name" Type="Str">CDM v2.10.00 WHQL Certified.exe</Property>
				<Property Name="Source[4].runEXE" Type="Bool">true</Property>
				<Property Name="Source[4].tag" Type="Ref">/My Computer/CCM_0001_Unipolar_Stepper_Motor_Controller/RevA/ftdi/CDM v2.10.00 WHQL Certified.exe</Property>
				<Property Name="Source[4].type" Type="Str">File</Property>
				<Property Name="Source[5].dest" Type="Str">{7D4A189D-D63C-4862-B44C-516F6FE87F09}</Property>
				<Property Name="Source[5].File[0].dest" Type="Str">{A0FD48CD-57E6-4B7E-9BE4-0014171B99D2}</Property>
				<Property Name="Source[5].File[0].name" Type="Str">Unipolar_Stepper_Motor_Controller.aliases</Property>
				<Property Name="Source[5].File[0].tag" Type="Ref"></Property>
				<Property Name="Source[5].name" Type="Str">usbview.exe</Property>
				<Property Name="Source[5].tag" Type="Ref">/My Computer/CCM_0001_Unipolar_Stepper_Motor_Controller/RevA/ftdi/usbview.exe</Property>
				<Property Name="Source[5].type" Type="Str">File</Property>
				<Property Name="Source[6].dest" Type="Str">{7D4A189D-D63C-4862-B44C-516F6FE87F09}</Property>
				<Property Name="Source[6].File[0].dest" Type="Str">{A0FD48CD-57E6-4B7E-9BE4-0014171B99D2}</Property>
				<Property Name="Source[6].File[0].name" Type="Str">FIRMWARE.ASM</Property>
				<Property Name="Source[6].File[0].tag" Type="Ref"></Property>
				<Property Name="Source[6].name" Type="Str">FT_Prog.exe</Property>
				<Property Name="Source[6].tag" Type="Ref">/My Computer/CCM_0001_Unipolar_Stepper_Motor_Controller/RevA/ftdi/FT_Prog.exe</Property>
				<Property Name="Source[6].type" Type="Str">File</Property>
				<Property Name="Source[7].dest" Type="Str">{7D4A189D-D63C-4862-B44C-516F6FE87F09}</Property>
				<Property Name="Source[7].File[0].dest" Type="Str">{A0FD48CD-57E6-4B7E-9BE4-0014171B99D2}</Property>
				<Property Name="Source[7].File[0].name" Type="Str">CDM v2.10.00 WHQL Certified.exe</Property>
				<Property Name="Source[7].File[0].tag" Type="Ref"></Property>
				<Property Name="Source[7].name" Type="Str">FT_Prog-CmdLine.exe</Property>
				<Property Name="Source[7].tag" Type="Ref">/My Computer/CCM_0001_Unipolar_Stepper_Motor_Controller/RevA/ftdi/FT_Prog-CmdLine.exe</Property>
				<Property Name="Source[7].type" Type="Str">File</Property>
				<Property Name="Source[8].dest" Type="Str">{7D4A189D-D63C-4862-B44C-516F6FE87F09}</Property>
				<Property Name="Source[8].File[0].dest" Type="Str">{A0FD48CD-57E6-4B7E-9BE4-0014171B99D2}</Property>
				<Property Name="Source[8].File[0].name" Type="Str">CCM_0001_Documentation.tex</Property>
				<Property Name="Source[8].File[0].tag" Type="Ref"></Property>
				<Property Name="Source[8].name" Type="Str">stepper_ftdi_config.bat</Property>
				<Property Name="Source[8].tag" Type="Ref">/My Computer/CCM_0001_Unipolar_Stepper_Motor_Controller/RevA/ftdi/stepper_ftdi_config.bat</Property>
				<Property Name="Source[8].type" Type="Str">File</Property>
				<Property Name="Source[9].dest" Type="Str">{7D4A189D-D63C-4862-B44C-516F6FE87F09}</Property>
				<Property Name="Source[9].File[0].dest" Type="Str">{A0FD48CD-57E6-4B7E-9BE4-0014171B99D2}</Property>
				<Property Name="Source[9].File[0].name" Type="Str">bootloader.asm</Property>
				<Property Name="Source[9].File[0].tag" Type="Ref"></Property>
				<Property Name="Source[9].name" Type="Str">AN_124_User_Guide_For_FT_PROG.pdf</Property>
				<Property Name="Source[9].tag" Type="Ref">/My Computer/CCM_0001_Unipolar_Stepper_Motor_Controller/RevA/ftdi/AN_124_User_Guide_For_FT_PROG.pdf</Property>
				<Property Name="Source[9].type" Type="Str">File</Property>
				<Property Name="SourceCount" Type="Int">11</Property>
			</Item>
		</Item>
	</Item>
</Project>
