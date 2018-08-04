#!/usr/bin/env python
# -*- coding: utf-8 -*-

import base64
import lxml.etree as ET
import zlib

xslt_text = """<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
        <xsl:output method="xml" indent="yes" />
        <xsl:template match="/">
                <testsuites>
                        <xsl:variable name="buildName" select="//Site/@BuildName"/>
                        <xsl:variable name="numberOfTests" select="count(//Site/Testing/Test)"/>
                        <xsl:variable name="numberOfFailures" select="count(//Site/Testing/Test[@Status!='passed'])" />
                        <testsuite name="CTest"
                                tests="{$numberOfTests}" time="0"
                                failures="{$numberOfFailures}"  errors="0"
                                skipped="0">
                        <xsl:for-each select="//Site/Testing/Test">
                                        <xsl:variable name="testName" select="translate(Name, '-', '_')"/>
                                        <xsl:variable name="duration" select="Results/NamedMeasurement[@name='Execution Time']/Value"/>
                                        <xsl:variable name="status" select="@Status"/>
                                        <xsl:variable name="output" select="Results/Measurement/Value"/>
                                        <xsl:variable name="className" select="translate(Path, '/.', '.')"/>
                                        <testcase classname="projectroot{$className}"
                                                name="{$testName}"
                                                time="{$duration}">
                                                <xsl:if test="@Status!='passed'">
                                                        <failure>
                                                                <xsl:value-of select="$output" />
                                                        </failure>
                                                </xsl:if>
                                                <system-out>
                                                        <xsl:value-of select="$output" />
                                                </system-out>
                                        </testcase>
                                </xsl:for-each>
                        </testsuite>
                </testsuites>
        </xsl:template>
</xsl:stylesheet>
"""
with open("Testing/TAG", "r") as tag_file:
    test_tag = tag_file.readline().strip()
    input_xml = ET.parse("Testing/{}/Test.xml".format(test_tag))
    xslt = ET.XML(xslt_text.encode("utf-8"))
    transformation = ET.XSLT(xslt)
    output_xml = transformation(input_xml)
    output_nodes = output_xml.xpath("//testsuites/testsuite/testcase/system-out")
    for node in output_nodes:
        base64_text = node.text
        unbased_text = base64.standard_b64decode(base64_text)
        ungzipped_text = zlib.decompress(unbased_text)
        node.text = ungzipped_text
    with open("Testing/junit-result.xml", "w") as result_file:
        result_file.write(ET.tostring(output_xml, pretty_print=True).decode("utf-8"))

