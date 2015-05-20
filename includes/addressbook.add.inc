<?php

function addressbook_add($form, &$form_state, $contact = FALSE) {

  $firstname = isset ($contact->addressbook_name) ? $contact->addressbook_name : FALSE;
  $lastname = isset ($contact->addressbook_lastname) ? $contact->addressbook_lastname : FALSE;
  $email = isset ($contact->addressbook_email) ? $contact->addressbook_email : FALSE;
  $photo = isset ($contact->addressbook_photo) ? $contact->addressbook_photo : NULL;
  $phone = isset ($contact->addressbook_phone) ? $contact->addressbook_phone : FALSE;

  $form['addressbook_firstname'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter your first name'),
    '#description' => 'First name',
    '#required' => TRUE,
    '#default_value' => $firstname,
  );

  $form['addressbook_lastname'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter you Last name'),
    '#description' => 'Last name',
    '#required' => TRUE,
    '#default_value' => $lastname,
  );

  $form['addressbook_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter your email'),
    '#description' => 'Email',
    '#required' => TRUE,
    '#default_value' => $email,
  );

  $form['addressbook_phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter your phone number'),
    '#description' => 'Phone',
    '#required' => TRUE,
    '#default_value' => $phone,
  );

  $form['addressbook_photo'] = array(
    '#type' => 'managed_file',
    '#title' => t('Photo'),
    '#required' => TRUE,
    '#description' => t('Allowed extensions: gif, png, jpg, jpeg'),
    '#upload_location' => 'public://addressbook/',
    '#upload_validators' => array(
      'file_validate_extensions' => array('gif png jpg jpeg'),
      'file_validate_size' => array(0.3 * 1024 * 1024),
      'file_validate_image_resolution' => array('400x400'),
    ),
    '#default_value' => $photo,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  return $form;
}

function addressbook_add_submit(&$form, &$form_state) {
 if (arg(4) == 'edit') {
   db_update('adressbook_table')
     ->fields(array(
       'addressbook_name' => $form['addressbook_firstname']['#value'],
       'addressbook_lastname' => $form['addressbook_lastname']['#value'],
       'addressbook_email' => $form['addressbook_email']['#value'],
       'addressbook_photo' => $form['addressbook_photo']['#value']['fid'],
       'addressbook_phone' => $form['addressbook_phone']['#value'],
     ))
     ->execute();
 } else {
   db_insert('adressbook_table')
     ->fields(array(
       'addressbook_name' => $form['addressbook_firstname']['#value'],
       'addressbook_lastname' => $form['addressbook_lastname']['#value'],
       'addressbook_email' => $form['addressbook_email']['#value'],
       'addressbook_photo' => $form['addressbook_photo']['#value']['fid'],
       'addressbook_phone' => $form['addressbook_phone']['#value'],
     ))
     ->execute();
 }
  drupal_goto('admin/content/contacts');
}