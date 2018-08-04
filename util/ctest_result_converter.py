#!/usr/bin/env python
# -*- coding: utf-8 -*-

import base64
import lxml.etree as ET
import zlib

with open("Testing/TAG", "r") as tag_file:
    test_tag = tag_file.readline().strip()
    input_xml = ET.parse("Testing/{}/Test.xml".format(test_tag))
    xslt = ET.parse("ctest-to-junit.xslt")
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

