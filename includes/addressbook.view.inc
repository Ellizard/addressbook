<?php

function addressbook_view($contact) {

  $photo = array(
    '#type'       => 'item',
    '#theme'      => 'image_style',
    '#style_name' => 'thumbnail',
    '#path'       => (file_load($contact->addressbook_photo)->uri),
  );

  $output = '';
  $output .= 'Photo: ' . drupal_render($photo) . '</br>';
  $output .= 'Name: ' . $contact->addressbook_name . '</br>';
  $output .= 'Lastname: ' . $contact->addressbook_lastname . '</br>';
  $output .= 'Email: ' . $contact->addressbook_email . '</br>';
  $output .= 'Phone: ' . $contact->addressbook_phone;

  return $output;
}