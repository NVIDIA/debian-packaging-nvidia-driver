#!/usr/bin/perl

# Copyright (C) 2018 Philipp Kern <pkern@debian.org>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.


use strict;
use warnings;

use Dpkg ();
use Dpkg::Control;
use Dpkg::Control::Info;
use Dpkg::Control::FieldsCore;
use Dpkg::Substvars;

# Dpkg::Control::FieldsCore insists on capitalizing field names on its
# own. This makes the custom field XS-Autobuild known to the library
# and avoids re-rendering the field's name.
Dpkg::Control::FieldsCore::field_register(
	'XS-Autobuild',
	CTRL_INFO_SRC,
	name => 'XS-Autobuild',
);

my $substvars = Dpkg::Substvars->new();

while (@ARGV) {
	$_ = shift(@ARGV);
	if (m/^-V(\w[-:0-9A-Za-z]*)[=:]/p) {
	        $substvars->set_as_used($1, ${^POSTMATCH});
	} elsif (m/^--$/p) {
		last;
	}
}

my $controlfile = $ARGV[0];
my $control = Dpkg::Control::Info->new($controlfile);

print "# NOTE: This file is generated from debian/control.in. To regenerate,\n";
print "# run \`make -f debian/rules debian/control'.\n";

my $src_fields = $control->get_source();
$src_fields->{'Source'} = $substvars->substvars($src_fields->{'Source'});
$src_fields->output(\*STDOUT);

foreach my $pkg_fields ($control->get_packages()) {
	print "\n";
	$pkg_fields->{'Package'} = $substvars->substvars($pkg_fields->{'Package'});
	$pkg_fields->output(\*STDOUT);
}
