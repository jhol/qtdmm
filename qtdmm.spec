Summary: Digital multimeter readout software.
Name: QtDMM
Version: 0.7
Release: 1
Copyright: GPL
Group: Applications/Engineering
Vendor: Matthias Toussaint
Source: http://www.mtoussaint.de/qtdmm-%{version}.tgz
URL: http://www.mtoussaint.de/qtdmm.html
Packager: Radek Liboska <liboska@uochb.cas.cz>
Buildroot: /tmp/%{name}-root
Requires: qt >= 2.1.0
BuildRequires: tmake
Icon: qtdmm.xpm
Prefix: /usr/X11R6

%description
QtDMM is a simple DMM readout software including a configurable recorder.
The recorder features manual start, scheduled start (at a given time)
and triggered automatic start when given thresholds are reached.
It was written for Metex (and compatible like VOLTCRAFT) multimeter
which use an 14 byte protocol. Additionally it was successfully tested
with an PeakTech-451 DMM which uses an slightly different 10 byte protocol.

%prep
%setup

export TMAKEPATH=/usr/share/tmake
%configure

%build
make

%install

rm -rf $RPM_BUILD_ROOT
install -d $RPM_BUILD_ROOT%prefix/bin
install -s -m 755 bin/qtdmm $RPM_BUILD_ROOT%prefix/bin

%clean
rm -rf $RPM_BUILD_ROOT

%files
%doc README
%defattr(-,root,root)
%prefix/bin/qtdmm

%changelog
* Wed Mar  6 2002 Radek Liboska <liboska@uochb.cas.cz>
- 0.7
* Tue Nov 27 2001 Radek Liboska <liboska@uochb.cas.cz>
- 0.6 
* Tue Sep  4 2001 Radek Liboska <liboska@uochb.cas.cz>
- 0.5 Second RPM release
- 0.4 Initial RPM release
